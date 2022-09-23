#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const int mod = 1e9 + 7;

using namespace std;

int n;
int k;
vector < int > a[15];
pair < int, int > nxt[15][N];
vector < pair < int, int > > cycle[1 << 15];
long long inf = 1e9;
map < int, pair < int, int > > id;
pair < int, int > ans[15];

int d[1 << 15];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        long long S = 0;
        for(int i = 0; i < n; i++){
                int g;
                cin >> g;
                a[i].resize(g);
                for(int j = 0; j < g; j++){
                        cin >> a[i][j];
                        S += a[i][j];
                        id[a[i][j]] = {i, j};
                }
        }
        if(S % n){
                cout << "No" << "\n";
                return 0;
        }
        S /= n;

        for(int i = 0; i < n; i++){
                long long A = 0;
                for(int x: a[i]){
                        A += x;
                }
                for(int j = 0; j < a[i].size(); j++){
                        if(abs(S - (A - a[i][j])) > inf){
                                continue;
                        }
                        nxt[i][j] = {-1, -1};
                        int need = S - (A - a[i][j]);
                        if(id.find(need) != id.end()){
                                nxt[i][j] = id[need];
                        }
                }
        }

        vector < pair < int, int > > path;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < a[i].size(); j++){
                        int mask = (1 << i);
                        path.clear();

                        pair < int, int > cur = {i, j};
                        if(nxt[i][j].fi == -1){
                                continue;
                        }
                        pair < int, int > to = nxt[cur.fi][cur.se];
                        path.push_back({a[i][j], cur.fi});
                        cur = to;
                        while((mask & (1 << cur.fi)) == 0){
                                mask |= (1 << cur.fi);
                                to = nxt[cur.fi][cur.se];
                                if(to.fi == -1){
                                        mask = -1;
                                        break;
                                }
                                path.push_back({a[cur.fi][cur.se], cur.fi});
                                cur = to;
                        }
                        if(mask == -1 || cur.fi != i || cur.se != j){
                                continue;
                        } else if(cycle[mask].empty()){
                                cycle[mask] = path;

                        }
                }
        }

        for(int i = 0; i < (1 << n); i++){
                d[i] = -1;
        }
        d[0] = 0;
        for(int i = 1; i < (1 << n); i++){
                for(int j = i; j > 0; j = (j - 1) & i){
                        if(cycle[j].empty()){
                                continue;
                        } else if(d[i ^ j] != -1){
                                d[i] = j;
                        }
                }
        }

        int mask = (1 << n) - 1;
        if(d[mask] == -1){
                cout << "No" << "\n";
                return 0;
        }
        cout << "Yes" << "\n";
        while(mask > 0){
                for(int i = 0; i < cycle[d[mask]].size(); i++){
                        int j = i - 1;
                        if(j < 0){
                                j += cycle[d[mask]].size();
                        }
                        auto p = cycle[d[mask]][i];
                        auto pre = cycle[d[mask]][j];
                        ans[p.se] = {p.fi, pre.se};
                }
                mask ^= d[mask];
        }
        for(int i = 0; i < n; i++){
                cout << ans[i].fi << " " << ans[i].se + 1 << "\n";
        }
}