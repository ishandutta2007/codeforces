//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int n, q;
int a[maxn];
int bpr[maxn];
int main() {
    for (int i = 0; i < maxn; i++)
        bpr[i] = 1;
    for (int i = 2; i < maxn; i++)
        for (int j = i * 2; j < maxn; j += i)
            bpr[j] = 0;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        multiset<ll> totw;
        vi prs;
        for (int j = 1; j < n; j++) 
            if (n % j == 0 && bpr[n / j]) prs.pb(j);
        vector<vector<ll > > tsum;
        tsum.resize(prs.size());
        int v = prs.size();
        for (int i = 0; i < v; i++) {
            tsum[i].resize(prs[i]);
            fill(tsum[i].begin(), tsum[i].end(), 0);
        }
        auto ins = [&](int id, int cur) {
            for (int j = 0; j < v; j++) {
                int bl = id % prs[j];
                auto h = totw.find(tsum[j][bl]);
                totw.erase(h);
                tsum[j][bl] += 1ll * cur * (prs[j]);
                totw.insert(tsum[j][bl]);
            }
        };
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < v; i++) {
            for (int j = 1; j <= n; j++)
                tsum[i][j % prs[i]] += 1ll * a[j] * (prs[i]);
            for (int j = 0; j < prs[i]; j++)
                totw.insert(tsum[i][j]);
        }
        auto otp = [&]() {
            ll ans = *totw.rbegin();
            printf("%lld\n", ans);
        };
        otp();
        for (int i = 1; i <= q; i++) {
            int p, to;
            scanf("%d%d", &p, &to);
            ins(p, to - a[p]);
            a[p] = to;
            otp();
        }
    }
    return (0 - 0); 
}