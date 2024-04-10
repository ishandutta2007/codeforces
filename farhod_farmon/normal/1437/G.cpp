#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int G;
int t[N][26];
int link[N];
pair < int, int > par[N];

int go(int x, int c);

int get_link(int x)
{
        if(link[x] == -1){
                if(x == 0 || par[x].fi == 0){
                        link[x] = 0;
                } else{
                        link[x] = go(get_link(par[x].fi), par[x].se);
                }
        }
        return link[x];
}

int go(int x, int c)
{
        if(t[x][c] == -1){
                t[x][c] = (x == 0 ? 0 : go(get_link(x), c));
        }
        return t[x][c];
}

int n, m;
int tim;
int a[N];
int tin[N];
int tout[N];
int id[N];
vector < int > v[N];

void dfs(int x)
{
        tin[x] = ++tim;
        for(int y: v[x]){
                dfs(y);
        }
        tout[x] = tim;
}

priority_queue < pair < int, int > > T[4 * N];

void upd(int x, int l, int r, int tl, int tr, int i)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                T[x].push({a[i], i});
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), i);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, i);
}

int get(int x, int l, int r, int i)
{
        int res = -1;
        while(!T[x].empty() && a[T[x].top().se] != T[x].top().fi){
                T[x].pop();
        }
        if(!T[x].empty()){
                res = T[x].top().fi;
        }
        if(l == r){
                return res;
        }
        int m = (l + r) / 2;
        if(i <= m){
                res = max(res, get(x * 2, l, m, i));
        } else{
                res = max(res, get(x * 2 + 1, m + 1, r, i));
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        for(int i = 0; i < N; i++){
                for(int j = 0; j < 26; j++){
                        t[i][j] = -1;
                }
                link[i] = -1;
        }
        cin >> n >> m;
        vector < int > shit;
        for(int i = 1; i <= n; i++){
                string s;
                cin >> s;
                int x = 0;
                for(char c: s){
                        int g = c - 'a';
                        if(t[x][g] == -1){
                                t[x][g] = (++G);
                                par[G] = {x, g};
                        }
                        x = t[x][g];
                }
                id[i] = x;
                shit.push_back(i);
        }
        for(int i = 1; i <= G; i++){
                v[get_link(i)].push_back(i);
        }
        dfs(0);
        for(int x: shit){
                upd(1, 1, G + 1, tin[id[x]], tout[id[x]], x);
                //cout << tin[x] << " " << tout[x] << "\n";
        }

        for(int i = 1; i <= m; i++){
                int t;
                cin >> t;
                if(t == 1){
                        int j, x;
                        cin >> j >> x;
                        a[j] = x;
                        upd(1, 1, G + 1, tin[id[j]], tout[id[j]], j);
                } else{
                        string s;
                        cin >> s;
                        int res = -1, x = 0;
                        for(char c: s){
                                x = go(x, c - 'a');
                                res = max(res, get(1, 1, G + 1, tin[x]));
                        }
                        cout << res << "\n";
                }
        }
}