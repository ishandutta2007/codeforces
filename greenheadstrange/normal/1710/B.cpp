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
#define maxn 200005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int n;
vector<pi> pls;
int x[maxn], p[maxn];
ll sk[maxn], sb[maxn];
int tr[maxn];
void act(int l, int r, int tk, int tb) {
    int ls = lower_bound(tr + 1, tr + n + 1, l) - tr;
    int rs = lower_bound(tr + 1, tr + n + 1, r + 1) - tr - 1;
    if (ls > rs) return  ;
    sk[ls] += tk; sb[ls] += tb;
    sk[rs + 1] -= tk; sb[rs + 1] -= tb;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            sk[i] = sb[i] = 0;
        vi cr;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &x[i], &p[i]);
            cr.pb(x[i]);
        }
        sort(cr.begin(), cr.end());
        for (int i = 1; i <= n; i++)
            tr[i] = cr[i - 1];
        for (int i = 1; i <= n; i++) {
            act(x[i] - p[i], x[i], 1, -x[i] + p[i]);
            act(x[i] + 1, x[i] + p[i], -1, x[i] + p[i]);
        }
        ll bmn = -2e9, bad = -2e9;
        for (int i = 1; i <= n; i++) {
            sk[i] += sk[i - 1], 
            sb[i] += sb[i - 1];
            int pl = tr[i];
            ll cur = sb[i] + 1ll * pl * sk[i];
            if (cur > m) {
                ll nd = cur - m;
                chkmax(bmn, nd - pl);
                chkmax(bad, nd + pl);
            }
        }
        for (int i = 1; i <= n; i++) {
            int flag = (p[i] + x[i] >= bad && p[i] - x[i] >= bmn);
            printf("%d", flag);
        }
        printf("\n");
    }
    return (0-0); //<3
}