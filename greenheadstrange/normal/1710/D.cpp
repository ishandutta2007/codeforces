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
const int maxn = 2005;
int fl[maxn][maxn];
int mxto[maxn][maxn];
int n;
char s[maxn];
void ade(int a, int b) {
    printf("%d %d\n", a, b);
}
void work(int l, int r) {
    if (l == r) return ;
    vector<pi> cur;
    int stl = l;
    while (l <= r) {
        int pl = mxto[l][r];
        if (l == stl) pl = mxto[l][r - 1];
        cur.pb(mp(l, pl));
        work(l, pl);
        l = pl + 1;
    }
    int sz = cur.size();
    if (sz == 2) {
        
        for (int l = cur[0].se; l >= cur[0].fi; l--)
            for (int r = cur[1].fi; r <= cur[1].se; r++) 
                if (fl[l][r]) {
                    assert(r == cur[1].se);
                    ade(l, r);
                    goto out;
                }
        out: ;
    }
    else {
        assert(sz >= 4);
        vi tt;
        for (int j = 0; j < 2; j++) {
            int start = sz - 1; 
            if (start % 2 != j) start--;
            for (int i = start; i >= 0; i -= 2)
                tt.pb(i);
        }
        if ((sz - 1) % 2 == 0) {
            assert(tt[0] == sz  - 1);
            for (int i = 0; i < tt.size(); i++) {
                if (tt[i] == 2) {
                    swap(tt[i], tt[0]);
                    break;
                }
            }
        }
        int bst1 = 0;
        for (int l = cur[0].se; l >= cur[0].fi; l--)
            if (fl[l][cur[sz - 1].se]) {
                bst1 = l;
                break;
            }
        auto gt = [&](int id) {
            if (id == 0) return bst1;
            else if (id == sz - 1) return cur[id].se;
            return cur[id].fi;
        };
        for (int i = 0; i + 1 < tt.size(); i++) {
            int u = tt[i], v = tt[i + 1];
            ade(gt(u), gt(v));
        }
    } 
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%s", s + i);
            for (int j = i; j <= n; j++)
                fl[i][j] = s[j] - '0';
            for (int j = i; j <= n; j++) {
                mxto[i][j] = mxto[i][j - 1];
                if (fl[i][j])
                    mxto[i][j] = j;
            }
        }
        work(1, n);
    }
    return (0-0); //<3
}
/*
6
4 5 2 6 1 3
*/