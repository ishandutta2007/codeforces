#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
int a[N];
int p[N];
int tim;
int tin[N];
int tout[N];
vector < int > v[N];

int t[4 * N];

void dfs(int x, int l, int p = -1)
{
        tin[x] = ++tim;
        a[x] = l;
        ::p[x] = p;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, l + 1, x);
        }
        tout[x] = tim;
}

void upd(int x, int l, int r, int tl, int tr, int y)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                t[x] = max(t[x], y);
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
}

int get(int x, int l, int r, int g)
{
        if(l == r){
                return t[x];
        }
        int m = (l + r) / 2;
        if(g <= m){
                return max(t[x], get(x * 2, l, m, g));
        }
        else{
                return max(t[x], get(x * 2 + 1, m + 1, r, g));
        }
}

bool used[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        k = n - k - 1;
        used[n] = 1;
        dfs(n, 0);
        for(int i = n - 1; i >= 1; i--){
                if(used[i]){
                        continue;
                }
                int g = a[i] - get(1, 1, n, tin[i]);
                if(g <= k){
                        k -= g;
                        int x = i;
                        while(!used[x]){
                                used[x] = 1;
                                for(int y: v[x]){
                                        if(y == p[x]){
                                                continue;
                                        }
                                        upd(1, 1, n, tin[y], tout[y], a[x]);
                                }
                                x = p[x];
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        cout << i << " ";
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}