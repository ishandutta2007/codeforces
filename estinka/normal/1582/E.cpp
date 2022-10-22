#include <iostream>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];
ll pf[maxn];
bool pv[maxn], nw[maxn]; // predosle dobre zaciatky a nove dobre zaciatky
ll sum(int l, int r)
{
    return pf[r] - pf[l - 1];
}
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
        for (int i = 1; i <= n; i++) cin >> a[i], pf[i] = pf[i - 1] + a[i], pv[i] = true;
        for (int k = 1; k <= n; k++) // ideme skusit k+1
        {
            for (int i = 1; i <= n; i++) nw[i] = false;
            ll maxi = -1;
            bool ok = false;
            for (int r = n; r >= 1; r--) // posledny prvok noveho intervalu
            {
                int l = r - k;
                if (l <= 0) break;
                if (sum(l, r) < maxi) nw[l] = ok = true;
                if (pv[r]) maxi = max(maxi, sum(r, r + k - 1));
            }
            if (!ok)
            {
                cout << k << "\n";
                break;
            }
            for (int i = 1; i <= n; i++) pv[i] = nw[i];
        }
        for (int i = 0; i < n + 5; i++) a[i] = pf[i] = pv[i] = nw[i] = 0;
    }
    return 0;
}