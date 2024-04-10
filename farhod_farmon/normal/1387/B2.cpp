#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];
int s[N];
int root = -1;
long long res;
vector < int > v[N], G;
pair < int, int > e = {-1, -1};

void dfs(int x, int p)
{
        int mx = 0;
        s[x] = 1;
        for(int y: v[x]){
                if(y == p) continue;
                dfs(y, x);
                s[x] += s[y];
                mx = max(mx, s[y]);
                res += min(s[y], n - s[y]) * 2;

                if(n % 2 == 0 && s[y] == n / 2){
                        e = {x, y};
                }
        }
        mx = max(mx, n - s[x]);
        if(mx < (n + 1) / 2){
                root = x;
        }
}

void run(int x, int p)
{
        G.push_back(x);
        for(int y: v[x]){
                if(y == p) continue;
                run(y, x);
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1, x, y; i < n; i++){
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        for(int i = 1; i <= n; i++) a[i] = i;
        dfs(1, 1);
        if(root != -1){
                int shift = (n + 1) / 2 - 1;
                for(int x: v[root]){
                        run(x, root);
                }
                for(int i = 0; i < n - 1; i++){
                        a[G[i]] = G[(i + shift) % (n - 1)];
                }
                swap(a[root], a[v[root][0]]);
        } else{
                assert(e.fi != -1);
                run(e.fi, e.se);
                auto V = G;
                G.clear();
                run(e.se, e.fi);
                for(int i = 0; i < n / 2; i++){
                        a[V[i]] = G[i];
                        a[G[i]] = V[i];
                }
        }
        cout << res << "\n";
        for(int i = 1; i <= n; i++) cout << a[i] << " ";
}