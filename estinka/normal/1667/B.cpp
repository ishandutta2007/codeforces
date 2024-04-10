#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

const int inf = 1e9;
void chm(int& a, int b)
{
    a = max(a, b);
}
struct intervalac
{
    // range maximum, point update
    int maxn;
    vector<int> st;
    void init(int n)
    {
        maxn = 1;
        while (maxn <= n) maxn <<= 1;
        st.assign(maxn * 2, -inf);
    }
    void upd(int i, int x)
    {
        for (i += maxn; i > 0; i >>= 1) chm(st[i], x);
    }
    int query(int l, int r)
    {
        int ans = -inf;
        for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) chm(ans, st[l++]);
            if (r & 1) chm(ans, st[--r]);
        }
        return ans;
    }
};
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
        vector<ll> a(n + 1);
        vector<ll> pf(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pf[i] = pf[i - 1] + a[i];
        }
        vector<ll> cs = pf;
        sort(cs.begin(), cs.end());
        cs.erase(unique(cs.begin(), cs.end()), cs.end());
        intervalac stz, st0, stk;
        stz.init(cs.size());
        st0.init(cs.size());
        stk.init(cs.size());
        vector<int> dp(n + 1, -inf);
        dp[0] = 0;
        for (int i = 0; i <= n; i++)
        {
            int id = lower_bound(cs.begin(), cs.end(), pf[i]) - cs.begin();
            if (i)
            {
                int vz = stz.query(id + 1, cs.size() - 1) - i;
                int v0 = st0.query(id, id);
                int vk = stk.query(0, id - 1) + i;
                dp[i] = max({ vz, v0, vk });
            }
            stz.upd(id, dp[i] + i);
            st0.upd(id, dp[i]);
            stk.upd(id, dp[i] - i);
        }
        //cout << "               ";
        cout << dp[n] << "\n";
    }
    return 0;
}