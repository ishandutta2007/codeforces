#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int G;
int c[N];
int ed[N];
bool used[N];
vector < int > v[N], g[N], ord;
vector < int > f[N], nv[N];

void dfs(int x)
{
        used[x] = 1;
        for(int y: v[x]){
                if(!used[y]){
                        dfs(y);
                }
        }
        ord.push_back(x);
}

void make(int x, int col)
{
        c[x] = col;
        f[col].push_back(x);
        for(int y: g[x]){
                if(!c[y]){
                        make(y, col);
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                g[y].push_back(x);
        }
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        dfs(i);
                }
        }
        for(int i = n - 1; i >= 0; i--){
                int x = ord[i];
                if(c[x]){
                        continue;
                }
                G++;
                make(x, G);
        }
        for(int i = 1; i <= n; i++){
                for(int j: v[i]){
                        if(c[i] == c[j]){
                                continue;
                        }
                        nv[c[i]].push_back(c[j]);
                        ed[c[j]]++;
                }
        }
        set < int > guys;
        for(int i = 1; i <= G; i++){
                if(!ed[i]){
                        guys.insert(i);
                }
        }
        int x = *guys.begin();
        int res = f[x].back();
        f[x].pop_back();
        guys.erase(x);
        while(!guys.empty()){
                x = *guys.begin();
                guys.erase(x);
                int y = f[x].back();
                f[x].pop_back();
                cout << "? " << res << " " << y << endl;
                int ans;
                cin >> ans;
                if(ans == 1){
                        if(f[x].size() > 0){
                                guys.insert(x);
                                continue;
                        }
                        for(int z: nv[x]){
                                ed[z]--;
                                if(ed[z] == 0){
                                        guys.insert(z);
                                }
                        }
                        continue;
                }
                swap(res, y);
                x = c[y];
                if(f[x].size() > 0){
                        guys.insert(x);
                        continue;
                }
                for(int z: nv[x]){
                        ed[z]--;
                        if(ed[z] == 0){
                                guys.insert(z);
                        }
                }
        }
        cout << "! " << res << endl;
}