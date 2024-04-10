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
int fa[maxn];
int gfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = gfa(fa[x]);
}
char s[maxn];
int st[maxn], top; // brak
pi stp[maxn]; int topp;
void ade(int l, int r) {
    fa[gfa(l)] = gfa(r);
}
int main() {    
    int t;
    cin >> t;
    while (t--) {
        top = 0, topp = 0;
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        int N = 2 * n;
        for (int i = 1; i <= N; i++) fa[i] = i;
        for (int i = 1; i <= N; i++) {
            if (s[i] == '(') st[top++] = i;
            else {
                int u = st[top - 1];
                ade(u, i);
                top--;
                while (topp > 0 && stp[topp - 1].fi > u) 
                    topp--;
                int umx = 0;
                if (top) umx = st[top - 1];
                if (topp > 0 && stp[topp - 1].fi > umx)
                    ade(i, stp[topp - 1].fi);
                stp[topp++] = mp(u, i);
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++)
            if (fa[i] == i) ans += 1;
        printf("%d\n", ans);
    }
    return 0;
}