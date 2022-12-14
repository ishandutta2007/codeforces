#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <bitset>
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b = a;
        sort(b.begin(), b.end());
        int kl = (n + k + 1) / 2;
        int x = 1, y = n;
        for (int i = 0; i + kl - 1 < n; i++)
        {
            int nwx = b[i], nwy = b[i + kl - 1];
            if (nwy - nwx <= y - x)
            {
                x = nwx;
                y = nwy;
            }
        }
        cout << x << " " << y << "\n";
        vector<int> pf(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pf[i + 1] = pf[i];
            if (x <= a[i] && a[i] <= y) pf[i + 1]++;
            else pf[i + 1]--;
        }
        vector<int> wh(k + 1, -1);
        for (int i = 0; i <= n; i++)
        {
            if (0 <= pf[i] && pf[i] <= k && wh[pf[i]] == -1)
            {
                wh[pf[i]] = i;
            }
        }
        wh[k] = n;
        for (int i = 0; i < k; i++)
        {
            cout << wh[i] + 1 << " " << wh[i + 1] << "\n";
        }
        //cout << "\n";
    }
    return 0;
}