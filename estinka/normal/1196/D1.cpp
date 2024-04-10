#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int>v;
        for (char c : s)
        {
            if (c == 'R')
            {
                v.push_back(0);
            }
            if (c == 'G')
            {
                v.push_back(1);
            }
            if (c == 'B')
            {
                v.push_back(2);
            }
        }
        int mini = k;
        for (int i = 0; i < 3; i++)
        {
            int changes = 0;
            for (int j = 0; j < k; j++)
            {
                if (v[j] != (i + j) % 3)
                {
                    changes++;
                }
            }
            mini = min(changes, mini);
            for (int j = k; j < n; j++)
            {
                if (v[j-k] != (i + j - k) % 3)
                {
                    changes--;
                }
                if (v[j] != (i + j) % 3)
                {
                    changes++;
                }
                mini = min(changes, mini);
            }
        }
        cout << mini << "\n";
    }
    return 0;
}