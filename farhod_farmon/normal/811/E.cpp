#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

struct node
{
        int cnt;
        pair < int, int > l[11], r[11];
};

int n;
int m;
int q;
int a[11][N];
node ans;
node t[4 * N];

node merg(node x, node y)
{
        node v;
        v.cnt = x.cnt + y.cnt;
        for(int i = 1; i <= n; i++){
                v.l[i] = x.l[i];
                v.r[i] = y.r[i];
        }
        for(int i = 1; i <= n; i++){
                if(x.r[i].fi == y.l[i].fi && x.r[i].se != y.l[i].se){
                        v.cnt--;
                        int nch = y.l[i].se;
                        for(int j = 1; j <= n; j++){
                                if(v.r[j].se == nch){
                                        v.r[j].se = x.r[i].se;
                                }
                                if(v.l[j].se == nch){
                                        v.l[j].se = x.r[i].se;
                                }
                                if(x.r[j].se == nch){
                                        x.r[j].se = x.r[i].se;
                                }
                                if(y.l[j].se == nch){
                                        y.l[j].se = x.r[i].se;
                                }
                        }
                }
        }
        return v;
}

void build(int x, int l, int r)
{
        if(l == r){
                t[x].cnt = n;
                for(int i = 1; i <= n; i++){
                        int p = i * m + l;
                        if(i > 1 && a[i][l] == a[i - 1][l]){
                                p = t[x].l[i - 1].se;
                                t[x].cnt--;
                        }
                        t[x].l[i] = t[x].r[i] = {a[i][l], p};
                }
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = merg(t[x * 2], t[x * 2 + 1]);
}

void get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                if(ans.cnt == 0){
                        ans = t[x];
                }
                else{
                        ans = merg(ans, t[x]);
                }
                return;
        }
        int m = (l + r) / 2;
        get(x * 2, l, m, tl, min(m, tr));
        get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

void solve()
{
        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                }
        }
        build(1, 1, m);
        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                ans.cnt = 0;
                get(1, 1, m, l, r);
                cout << ans.cnt << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}