#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.size() > 1 && s[0] == s[1])
        {
            cout << s[0] << s[1] << "\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1 && s[i] < s[i + 1])
            {
                while (s.size() != i + 1) s.pop_back();
                break;
            }
        }
        string best = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        best += s2;
        cout << best << "\n";
    }
    return 0;
}