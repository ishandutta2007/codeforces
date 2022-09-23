#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int p[N];
int s[N];
int lef[N];
int righ[N];
bool used[N];
int goods[N];
vector < int > v[N], vg[N], ord;

void dfs(int x)
{
        used[x] = 1;
        for(int y: v[x]){
                if(used[y]){
                        continue;
                }
                dfs(y);
        }
        ord.push_back(x);
}

int get(int x)
{
        return x == p[x] ? x : p[x] = get(p[x]);
}
set < int > f;
void upd(int x, int y)
{
        if(y != get(y)){
                return;
        }
        x = get(x);
        y = get(y);
        if(x == y){
                return;
        }
        p[y] = x;
        f.erase(y);
}

set < int > gg[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                vg[y].push_back(x);
        }
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        dfs(i);
                }
                p[i] = i;
                s[i] = 1;
        }
        for(int i = 1; i <= n; i++){
                used[i] = 0;
        }
        reverse(ord.begin(), ord.end());
        for(int i = ord.size() - 1; i >= 0; i--){
                int x = ord[i];
                f.insert(x);
                for(int y: v[x]){
                        upd(x, y);
                        if(used[y]){
                                goods[x]++;
                        }
                        else{
                                gg[y].insert(x);
                                if(gg[y].size() > 1){
                                        used[y] = true;
                                        for(int x: gg[y]){
                                                goods[x] += 1;
                                        }
                                }
                        }
                }
                if(f.size() > 1){
                        if(f.size() > 2){
                                righ[i] = 2;
                        }
                        else{
                                righ[i] = 2;
                                auto p = f.begin();
                                if(goods[*p] == v[*p].size() && *p != x){
                                        righ[i] = 1;
                                }
                                p++;
                                if(goods[*p] == v[*p].size() && *p != x){
                                        righ[i] = 1;
                                }
                        }
                }
        }
        f.clear();
        for(int i = 1; i <= n; i++){
                used[i] = 0;
                goods[i] = 0;
                gg[i].clear();
                p[i] = i;
        }
        for(int i = 0; i < ord.size(); i++){
                int x = ord[i];
                f.insert(x);
                for(int y: vg[x]){
                        upd(x, y);
                        if(used[y]){
                                goods[x]++;
                        }
                        else{
                                gg[y].insert(x);
                                if(gg[y].size() > 1){
                                        used[y] = true;
                                        for(int x: gg[y]){
                                                goods[x] += 1;
                                        }
                                }
                        }
                }
                if(f.size() > 1){
                        if(f.size() > 2){
                                lef[i] = 2;
                        }
                        else{
                                lef[i] = 2;
                                auto p = f.begin();
                                if(goods[*p] == vg[*p].size() && *p != x){
                                        lef[i] = 1;
                                }
                                p++;
                                if(goods[*p] == vg[*p].size() && *p != x){
                                        lef[i] = 1;
                                }
                        }
                }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
                ans += (lef[i] + righ[i]) <= 1;
        }
        cout << ans << "\n";
}