#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <list>
typedef long long ll;
using namespace std;

bool check(string s, int m)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ((m& (1 << (s[i] - 'A')))) cnt++;
        else cnt--;
        if (cnt < 0) return false;
    }
    return cnt == 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool ans = false;
        for (int i = 0; i < (1 << 3); i++) ans |= check(s, i);
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0; 
}