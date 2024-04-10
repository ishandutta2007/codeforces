#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

bool solve()
{
    vector<int> v1(2), v2(2); // v2[0] = AB, v2[1] = BA
    cin >> v1[0] >> v1[1] >> v2[0] >> v2[1];
    string s;
    cin >> s;
    int ca = count(s.begin(), s.end(), 'A'), cb = count(s.begin(), s.end(), 'B');
    if (ca != v1[0] + v2[0] + v2[1] || cb != v1[1] + v2[0] + v2[1]) return false;
    vector<vector<int> > l(2);
    int both = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int j = i; 
        while (j + 1 < s.size() && s[j] != s[j + 1]) j++;
        int len = j - i + 1;
        if (len & 1) both += len / 2;
        else if (s[i] == 'A') l[0].push_back(len / 2);
        else if (s[i] == 'B') l[1].push_back(len / 2);
        i = j;
    }
    sort(l[0].begin(), l[0].end());
    sort(l[1].begin(), l[1].end());
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < l[i].size(); j++)
        {
            int cnt = min(v2[i], l[i][j]);
            v2[i] -= cnt;
            l[i][j] -= cnt;
        }
        int cnt = min(v2[i], both);
        v2[i] -= cnt;
        both -= cnt;
        for (int j = (int)l[i ^ 1].size() - 1; j >= 0; j--) if (v2[i] && l[i ^ 1][j])
        {
            int cnt = min(v2[i], l[i ^ 1][j] - 1);
            v2[i] -= cnt;
            l[i ^ 1][j] -= cnt + 1;
        }
        if (v2[i])
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}