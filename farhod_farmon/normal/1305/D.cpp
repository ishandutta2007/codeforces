#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 1010;
const int Q = 400200;

using namespace std;

int n;
int par[N];
bool dead[N];
vector < int > v[N];

void dfs(int x, int p)
{
        par[x] = p;
        for(int y: v[x]){
                if(y == p) continue;
                dfs(y, x);
        }
}
int lca(int x, int y)
{
        cout << "? " << x << ' ' << y << endl;
        cin >> x;
        return x;
}
void ans(int x)
{
        cout << "! " << x << endl;
        exit(0);
}
void make(int x, int p)
{
        dead[x] = true;
        for(int y: v[x]){
                if(y  == p) continue;
                make(y, x);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1, x, y; i < n; i++){
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        while(true){
                vector < int > G;
                for(int i = 1; i <= n; i++){
                        if(dead[i]){
                                continue;
                        }
                        int cnt = 0;
                        for(int j: v[i]){
                                if(!dead[j]){
                                        cnt += 1;
                                }
                        }
                        if(cnt <= 1){
                                G.push_back(i);
                        }
                }
                if(G.size() == 1){
                        ans(G[0]);
                } else if(G.size() == 2){
                        ans(lca(G[0], G[1]));
                }
                int x = G[0], y = G[1];
                int p = lca(x, y);
                if(p == x || p == y){
                        ans(p);
                }
                dfs(p, p);
                while(par[x] != p) x = par[x];
                while(par[y] != p) y = par[y];
                make(x, p);
                make(y, p);
        }
}