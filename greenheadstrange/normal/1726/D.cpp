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
int u[maxn], v[maxn];
struct dsu {
    int fa[maxn];
    int gfa(int a) {
        if (fa[a] == a) return a;
        return fa[a] = gfa(fa[a]);
    }
    void init(int n) {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }
    void ade(int a, int b) {
        fa[gfa(a)] = gfa(b);
    }
}h[2];
mt19937 rd(1234);
int col[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            scanf("%d%d", &u[i], &v[i]);
        while (1) {
            for (int i = 0; i < 2; i++)
                h[i].init(n);
            int flag = 1;
            for (int i = 1; i <= m; i++) {
                int ok[2] = {0, 0};
                for (int j = 0; j < 2; j++) 
                    ok[j] = (h[j].gfa(u[i]) != h[j].gfa(v[i]));
                if (!ok[0] && !ok[1]) {
                    flag = 0;
                    break;
                }
                int x;
                if (ok[0] && ok[1]) 
                    x = rd() % 2;
                else if (ok[0]) x = 0;
                else x = 1;
                h[x].ade(u[i], v[i]);
                col[i] = x;
            }
            if (flag) 
                break;
        }
        for (int i = 1; i <= m; i++)
            printf("%d", col[i]);
        printf("\n");
    }    
    return 0;
}