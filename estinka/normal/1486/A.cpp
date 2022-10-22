#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <array>
typedef long long ll;
typedef long double ld;
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
        vector<ll> h(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (!i)
            {
                h[i + 1] += h[i];
                h[i] = 0;
            }
            else
            {
                if (h[i] <= h[i - 1])
                {
                    flag = false;
                    break;
                }
                if (i == n - 1) continue;
                h[i + 1] += (h[i] - h[i - 1] - 1);
                h[i] = h[i - 1] + 1;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}