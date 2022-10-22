#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

bool good(string& s)
{
    int lvl = 0;
    for (int i = 0; i < s.size(); i++)
    {
        lvl += (s[i] == '(' ? 1 : -1);
        if (lvl < 0) return false;
    }
    return lvl == 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    string s2 = s, s3 = s;
    for (int i = 0; i < n; i++)
    {
        if (s2[i] == ')')
        {
            s2.erase(s2.begin() + i);
            s2.push_back(')');
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s3[i] == '(')
        {
            s3.erase(s3.begin() + i);
            s3.insert(s3.begin(), '(');
            break;
        }
    }
    if (good(s) || good(s2) || good(s3))
        cout << "Yes\n";
    else cout << "No\n";
    return 0;
}