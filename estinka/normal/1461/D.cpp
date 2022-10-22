#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxa = 1e6 + 7;
vector<ll> a, pf;
set<ll> s;
vector<int> oc(maxa, -1);
void go(int l, int r)
{
    s.insert(pf[r + 1] - pf[l]);
    if (a[l] == a[r]) return;
    int mid = (a[l] + a[r]) / 2;
    mid = oc[mid];
    if (mid == r) return;
    go(l, mid);
    go(mid + 1, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        a.assign(n, 0);
        pf.assign(n + 1, 0);
        s.clear();
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) oc[a[i]] = i;
        for (int i = 1; i < maxa; i++) oc[i] = max(oc[i], oc[i - 1]);
        for (int i = 0; i < n; i++)
            pf[i + 1] = pf[i] + a[i];
        go(0, n - 1);
        for (int i = 0; i < q; i++)
        {
            ll ss; cin >> ss;
            cout <<  (s.count(ss) ? "Yes" : "No") << "\n";
        }
        for (int i = 0; i < maxa; i++) oc[i] = -1;
    }
    return 0;
}