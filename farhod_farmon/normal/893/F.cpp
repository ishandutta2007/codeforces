#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

int L[N];

struct rmq
{
        int n;
        int l;
        vector < vector < int > > v;
        void create(vector < pair < int, int > > y)
        {
                l = 1;
                n = y.size();
                v.resize(n);
                while((1 << l - 1) <= n){
                        l++;
                }
                for(int i = 0; i < n; i++){
                        v[i].resize(l);
                        v[i][0] = y[i].se;
                }
                for(int j = 1; j < l; j++){
                        for(int i = 0; i < n; i++){
                                if(i + (1 << j) > n){
                                        continue;
                                }
                                v[i][j] = min(v[i][j - 1], v[i + (1 << j) / 2][j - 1]);
                        }
                }
        }
        int get(int l, int r)
        {
                if(l > r){
                        return 1e9;
                }
                int g = L[r - l + 1];
                return min(v[l][g], v[r - (1 << g) + 1][g]);
        }
};

int n;
int O;
int tim;
int a[N];
int dip[N];
int tin[N];
int tout[N];
vector < int > v[N];
vector < pair < int, int > > b[N];

void dfs(int x, int p)
{
        tim++;
        tin[x] = tim;
        dip[x] = dip[p] + 1;
        b[dip[x]].push_back({tin[x], a[x]});
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
        }
        tout[x] = tim;
}

rmq d[4 * N];
vector < pair < int, int > > t[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                for(auto p: b[l]){
                        t[x].push_back(p);
                }
                d[x].create(t[x]);
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        int i = 0, j = 0;
        for(; i < t[x * 2].size(); i++){
                while(j < t[x * 2 + 1].size() && t[x * 2 + 1][j] < t[x * 2][i]){
                        t[x].push_back(t[x * 2 + 1][j]);
                        j++;
                }
                t[x].push_back(t[x * 2][i]);
        }
        while(j < t[x * 2 + 1].size()){
                t[x].push_back(t[x * 2 + 1][j]);
                j++;
        }
        d[x].create(t[x]);
}

int get(int x, int l, int r, int tl, int tr, int nl, int nr)
{
        if(tl > tr || t[x].empty() || t[x][0].fi > nr || t[x].back().fi < nl){
                return 1e9;
        }
        if(l == tl && r == tr){
                int fl = lower_bound(t[x].begin(), t[x].end(), make_pair(nl, 0)) - t[x].begin(),
                    fr = lower_bound(t[x].begin(), t[x].end(), make_pair(nr + 1, 0)) - t[x].begin() - 1;
                return d[x].get(fl, fr);
        }
        int m = (l + r) / 2;
        return min(get(x * 2, l, m, tl, min(m, tr), nl, nr),
                   get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, nl, nr));
}

void solve()
{
        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }
        scanf("%d%d", &n, &O);
        for(int i = 1; i <= n; i++){
                scanf("%d", &a[i]);
        }
        for(int i = 1; i < n; i++){
                int x, y;
                scanf("%d%d", &x, &y);
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(O, O);
        build(1, 1, n);
        int last = 0, q;
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
                int x, k;
                scanf("%d%d", &x, &k);
                x = (x + last) % n + 1;
                k = (k + last) % n;
                last = get(1, 1, n, dip[x], min(n, dip[x] + k), tin[x], tout[x]);
                printf("%d\n", last);
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}