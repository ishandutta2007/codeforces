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

ll divup(ll a, ll b)
{
    return (a + b - 1) / b;
}
vector<int> st, lz;
// number of teachers - number of classes >= 0
int maxn;
void unlazy(int vr)
{
    st[vr << 1] += lz[vr];
    lz[vr << 1] += lz[vr];
    st[vr << 1 | 1] += lz[vr];
    lz[vr << 1 | 1] += lz[vr];
    lz[vr] = 0;
}
void upd(int l, int r, int d, int vr = 1, int li = 0, int ri = maxn - 1)
{
    if (ri < l || li > r) return;
    if (l <= li && ri <= r)
    {
        st[vr] += d;
        lz[vr] += d;
        return;
    }
    unlazy(vr);
    upd(l, r, d, vr << 1, li, (li + ri) >> 1);
    upd(l, r, d, vr << 1 | 1, ((li + ri) >> 1) + 1, ri);
    st[vr] = min(st[vr << 1], st[vr << 1 | 1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        a.resize(m);
        reverse(a.begin(), a.end());
        n = m;
        vector<vector<int> > b(n);
        vector<ll> sum(n);
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            b[i].resize(k);
            for (int j = 0; j < k; j++)
            {
                cin >> b[i][j];
                sum[i] += b[i][j];
            }
        }
        maxn = 1;
        while (maxn <= n) maxn <<= 1;
        st.assign(maxn * 2, 0);
        lz.assign(maxn * 2, 0);
        for (int i = 0; i < n; i++)
        {
            upd(0, i, 1);
            int avg = divup(sum[i], b[i].size());
            int it = lower_bound(a.begin(), a.end(), avg) - a.begin();
            upd(0, it, -1);
        }
        string ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < b[i].size(); j++)
            {
                int avg = divup(sum[i], b[i].size()), nw = divup(sum[i] - b[i][j], b[i].size() - 1);
                int it = lower_bound(a.begin(), a.end(), avg) - a.begin();
                int nwit = lower_bound(a.begin(), a.end(), nw) - a.begin();
                upd(0, it, 1);
                upd(0, nwit, -1);
                if (st[1] < 0) ans.push_back('0');
                else ans.push_back('1');
                upd(0, it, -1);
                upd(0, nwit, 1);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}