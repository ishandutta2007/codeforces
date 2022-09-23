#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int d[N];
vector < int > v[N];

int bfs(int x)
{
        d[x] = 1;
        queue < int > q;
        q.push(x);
        while(!q.empty()){
                x = q.front();
                q.pop();
                for(int y: v[x]){
                        if(d[y] == 0){
                                q.push(y);
                                d[y] = d[x] + 1;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                if(d[i] > d[x]){
                        x = i;
                }
        }
        return x;
}

int G;
int f[N];
int s[N];
int a[N];
int par[N];
int t[4 * N];
int lz[4 * N];
bool used[N];

void dfs(int x, int p = -1)
{
        par[x] = p;
        f[x] = G + 1;
        bool child = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                child = 0;
                d[y] = d[x] + 1;
                dfs(y, x);
        }
        G += child;
        if(child){
                a[G] = x;
        }
        s[x] = G;
}

void push(int x)
{
        if(lz[x]){
                t[x * 2] += lz[x];
                lz[x * 2] += lz[x];
                t[x * 2 + 1] += lz[x];
                lz[x * 2 + 1] += lz[x];
                lz[x] = 0;
        }
}

void build(int x, int l, int r)
{
        if(l > r){
                return;
        }
        if(l == r){
                t[x] = d[a[l]];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

pair < int, int > get(int x, int l, int r)
{
        if(l == r){
                return {l, t[x]};
        }
        push(x);
        int m = (l + r) / 2;
        if(t[x * 2] > t[x * 2 + 1]){
                return get(x * 2, l, m);
        }
        else{
                return get(x * 2 + 1, m + 1, r);
        }
}

void upd(int x, int l, int r, int tl, int tr, int g)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                t[x] += g;
                lz[x] += g;
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), g);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

void solve()
{
        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        int root = bfs(1);
        d[root] = 0;
        dfs(root);
        build(1, 1, G);
        cout << 1 << " ";
        int last = 1;
        for(int i = 2; i <= n; i++){
                if(last == n){
                        cout << n << " ";
                        continue;
                }
                pair < int, int > p = get(1, 1, G);
                int x = a[p.fi], cnt = 0;
                last += p.se;
                while(par[x] != -1 && used[par[x]] != 1){
                        cnt++;
                        used[par[x]] = 1;
                        for(int y: v[par[x]]){
                                if(y == par[par[x]] || y == x){
                                        continue;
                                }
                                upd(1, 1, G, f[y], s[y], cnt - p.se);
                        }
                        x = par[x];
                }
                upd(1, 1, G, p.fi, p.fi, -n);
                cout << last << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}