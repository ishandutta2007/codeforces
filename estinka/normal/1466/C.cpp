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
#include <list>
#include <array>
#include <fstream>
typedef long long ll;
typedef long double ld;
using namespace std;

bool eq(char a, char b)
{
    if (a == '?' || b == '?') return false;
    return a == b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        // we need to take care of 2- and 3- letter palindromes
        // dp - n * 26 * 26 ? 
        string s;
        cin >> s;
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 1 && eq(s[i - 2], s[i]) && eq(s[i - 1], s[i]))
            {
                s[i - 1] = s[i] = '?';
                cnt += 2;
            }
            else if (i > 1 && eq(s[i - 2], s[i]))
            {
                s[i] = '?';
                cnt++;
            }
            else if (i && eq(s[i - 1], s[i]))
            {
                s[i] = '?';
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}