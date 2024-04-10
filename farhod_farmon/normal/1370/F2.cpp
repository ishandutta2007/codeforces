#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 1010;

using namespace std;

int n;
int dip[N];
int par[N];
vector < int > v[N];

pair < int, int > get(vector < int > v, int ban = -1)
{
        int cnt = 0;
        for(int x: v){
                if(x == ban){
                        cnt = 1;
                }
        }
        if(cnt == v.size()){
                return {-1, -1};
        }
        cout << "? " << v.size() - cnt;
        for(int x: v){
                if(x == ban){
                        continue;
                }
                cout << " " << x;
        }
        cout << endl;
        int x, y;
        cin >> x >> y;
        return {x, y};
}

vector < int > G[N];

void dfs(int x, int p)
{
        G[dip[x]].push_back(x);
        for(int y: v[x]) if(y != p){
                dip[y] = dip[x] + 1;
                par[y] = x;
                dfs(y, x);
        }
}

int jump(int x, int y)
{
        assert(y >= 0);
        while(y--){
                x = par[x];
        }
        return x;
}

void solve()
{
        cin >> n;
        vector < int > all;
        for(int i = 1; i <= n; i++){
                v[i].clear();
                G[i - 1].clear();
                all.push_back(i);
        }
        for(int i = 1, x, y; i < n; i++){
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }

        auto shit = get(all);
        int root = shit.fi, D = shit.se;
        dip[root] = 0;
        dfs(root, root);

        int cur = max((D + 1) / 2 - 1, 0);
        int T = root, sss = 0;
        for(int i = 9; i >= 0; i--){
                if(cur + (1 << i) > D){
                        continue;
                }
                shit = get(G[cur + (1 << i)]);
                if(shit.se == D){
                        cur += (1 << i);
                        T = shit.fi;
                        sss = 1;
                }
        }
        if(!sss && cur > 0){
                T = get(G[cur]).fi;
        }
        int S = get(G[D - cur], jump(T, cur * 2 - D)).fi;
        if(cur == D){
                S = root;
        }
        cout << "! " << S << " " << T << endl;
        string suka;
        cin >> suka;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}