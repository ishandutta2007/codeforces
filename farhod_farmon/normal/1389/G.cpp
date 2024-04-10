#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n, m, k;
int p[N], w[N], A[N], B[N];
long long c[N];
vector < int > v[N];
int black[N];

int used[N], bridge[N];
int tim, tin[N], fin[N];

void dfs(int x, int p)
{
        used[x] = true;
        tin[x] = fin[x] = ++tim;
        for(int i: v[x]){
                int y = A[i] ^ B[i] ^ x;
                if(y == p){
                        continue;
                } else if(used[y]){
                        fin[x] = min(fin[x], tin[y]);
                } else{
                        dfs(y, x);
                        fin[x] = min(fin[x], fin[y]);
                        if(fin[y] > tin[x]){
                                bridge[i] = true;
                        }
                }
        }
}

int get_p(int x) { return p[x] == x ? x : p[x] = get_p(p[x]); }

void make(int x, int y)
{
        x = get_p(x);
        y = get_p(y);
        if(x != y){
                black[x] |= black[y];
                c[x] += c[y];
                p[y] = x;
        }
}

set < pair < int, int > > nv[N];
long long d[N];

void dfs2(int x, int p)
{
        d[x] = c[x];
        for(auto y: nv[x]){
                if(y.fi == p){
                        continue;
                }
                dfs2(y.fi, x);
                d[x] += max(0ll, d[y.fi] - y.se);
        }
}

void dfs3(int x, int p, long long u)
{
        d[x] += u;
        for(auto y: nv[x]){
                if(y.fi == p){
                        continue;
                }
                dfs3(y.fi, x, max(0ll, d[x] - max(0ll, d[y.fi] - y.se) - y.se));
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m >> k;
        for(int i = 1; i <= k; i++){
                int x;
                cin >> x;
                black[x] = 1;
        }
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                p[i] = i;
        }
        for(int i = 1; i <= m; i++){
                cin >> w[i];
        }
        for(int i = 1; i <= m; i++){
                cin >> A[i] >> B[i];
                v[A[i]].push_back(i);
                v[B[i]].push_back(i);
        }

        dfs(1, 1);

        for(int i = 1; i <= m; i++){
                if(!bridge[i]){
                        make(A[i], B[i]);
                }
        }
        for(int i = 1; i <= m; i++){
                if(bridge[i]){
                        int x = get_p(A[i]), y = get_p(B[i]);
                        nv[x].insert({y, w[i]});
                        nv[y].insert({x, w[i]});
                }
        }
        queue < int > solo;
        for(int i = 1; i <= n; i++){
                used[i] = false;
                if(get_p(i) != i){
                        used[i] = true;
                        continue;
                }
                if(nv[i].size() == 1 && !black[i]){
                        solo.push(i);
                }
        }
        while(!solo.empty()){
                int x = solo.front();
                solo.pop();
                used[x] = true;
                assert((int)nv[x].size() == 1);
                auto y = *nv[x].begin();
                nv[x].clear();
                nv[y.fi].erase({x, y.se});
                if(nv[y.fi].size() == 1 && !black[y.fi]){
                        solo.push(y.fi);
                }
                make(y.fi, x);
        }

        int root = -1;
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        root = i;
                }
        }

        dfs2(root, root);
        dfs3(root, root, 0);

        for(int i = 1; i <= n; i++){
                cout << d[get_p(i)] << " ";
        }
}