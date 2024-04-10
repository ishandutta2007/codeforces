#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 150050;
const int Q = 100100;
const int MAGIC = 130;

using namespace std;

int n;
int bad;
int p[N];
int h[N];
int u[N];
int pr[N];
int sum[N];
int d[N][27];
int f[N][27];
char c[N];
vector < int > v[N];

void dfs(int x)
{
        if(v[x].empty()){
                return;
        }
        assert(v[x].size() == 2);
        sum[x] = 0;
        int a = v[x][0], b = v[x][1];
        dfs(a);
        dfs(b);
        for(int i = 0; i < 26; i++){
                f[x][i] = max(f[a][i] + d[a][i], f[b][i] + d[b][i]);
                sum[x] += f[x][i];
        }
        bad += (sum[x] > h[x]);
}

void upd(int x, int c)
{
        while(x){
                bad -= sum[x] > h[x];
                sum[x] -= f[x][c];
                if(!v[x].empty()){
                        int a = v[x][0], b = v[x][1];
                        f[x][c] = max(f[a][c] + d[a][c], f[b][c] + d[b][c]);
                }
                sum[x] += f[x][c];
                bad += sum[x] > h[x];
                x = pr[x];
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> n >> q;
        for(int i = 2; i <= n; i++){
                cin >> p[i] >> c[i];
                h[i] = h[p[i]] + 1;
                v[p[i]].push_back(i);
        }
        int gg = -1;
        for(int i = 1; i <= n; i++){
                if(!v[i].empty()){
                        continue;
                }
                if(gg != -1 && h[i] != gg){
                        gg = -1;
                        break;
                }
                gg = h[i];
        }
        if(gg == -1){
                for(int i = 1; i <= q; i++){
                        cout << "Fou" << "\n";
                }
                return 0;
        }
        for(int i = n; i >= 1; i--){
                if(v[i].size() != 1){
                        u[i] = i;
                } else{
                        u[i] = u[v[i][0]];
                }
                pr[u[i]] = p[i];
                v[i].clear();
                if(i > 1){
                        if(c[i] != '?'){
                                d[u[i]][c[i] - 'a'] += 1;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                h[i] = gg - h[i];
                if(u[i] != i){
                        continue;
                }
                if(pr[i]){
                        v[pr[i]].push_back(i);
                }
        }
        for(int i = 1; i <= n; i++){
                if(u[i] != i){
                        continue;
                }
                //cout << i << ": ";
                //for(int x: v[i]){
                //        cout << x << " ";
                //}
                //cout << "\n";
        }
        dfs(u[1]);
        for(int i = 1; i <= q; i++){
                int x;
                char y;
                cin >> x >> y;
                if(c[x] != '?'){
                        d[u[x]][c[x] - 'a'] -= 1;
                        upd(u[x], c[x] - 'a');
                }
                c[x] = y;
                if(c[x] != '?'){
                        d[u[x]][c[x] - 'a'] += 1;
                        upd(u[x], c[x] - 'a');
                }
                if(bad){
                        cout << "Fou" << "\n";
                } else{
                        int res = 0, add = gg - sum[u[1]];
                        for(int i = 0; i < 26; i++){
                                add -= d[u[1]][i];
                        }
                        for(int i = 0; i < 26; i++){
                                res += (i + 1) * (f[u[1]][i] + d[u[1]][i] + add);
                        }
                        cout << "Shi" << " " << res << "\n";
                }
        }
}