#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int tim;
int p[N];
int tin[N];
int tout[N];
int f[N][17];
int L[N];
int s[N][17];
int dip[N];
vector < int > v[N];
pair < int, int > mn[N][17];
pair < int, int > mx[N][17];

void dfs(int x)
{
        f[x][0] = p[x];
        for(int i = 1; i < 17; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }
        tin[x] = ++tim;
        for(int y: v[x]){
                dip[y] = dip[x] + 1;
                dfs(y);
        }
        tout[x] = tim;
}

bool isp(int x, int y)
{
        return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y)
{
        if(isp(x, y)){
                return x;
        }
        if(isp(y, x)){
                return y;
        }
        for(int i = 16; i >= 0; i--){
                if(!isp(f[x][i], y)){
                        x = f[x][i];
                }
        }
        return f[x][0];
}

int myrand()
{
        int x = rand() % 10000;
        int y = rand() % 10000;
        return (x << 15) + y;
}

int get(int l, int r)
{
        if(l > r){
                return 0;
        }
        int g = L[r - l + 1];
        return lca(s[l][g], s[r - (1 << g) + 1][g]);
}

pair < int, int > get_mn(int l, int r)
{
        int g = L[r - l + 1];
        return min(mn[l][g], mn[r - (1 << g) + 1][g]);
}
pair < int, int > get_mx(int l, int r)
{
        int g = L[r - l + 1];
        return max(mx[l][g], mx[r - (1 << g) + 1][g]);
}

bool used[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> n >> q;
        for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);
                p[i] = x;
        }
        p[1] = 1;
        dfs(1);
        for(int i = 1; i <= n; i++){
                s[i][0] = i;
                mn[i][0] = {tin[i], i};
                mx[i][0] = {tin[i], i};
        }
        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }
        for(int i = 1; i < 17; i++){
                for(int j = 1; j <= n; j++){
                        if(j + (1 << i) - 1 > n){
                                continue;
                        }
                        s[j][i] = lca(s[j][i - 1], s[j + (1 << i - 1)][i - 1]);
                        mn[j][i] = min(mn[j][i - 1], mn[j + (1 << i - 1)][i - 1]);
                        mx[j][i] = max(mx[j][i - 1], mx[j + (1 << i - 1)][i - 1]);
                }
        }
        vector < int > g(70);
        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                int h, best = -1;
                /*for(int it = 0; it < 70; it++){
                        int x = myrand() % (r - l + 1) + l;
                        if(used[x]){
                                g[it] = 0;
                                continue;
                        }
                        used[x] = true;
                        g[it] = x;
                        int p1 = get(l, x - 1), p2 = get(x + 1, r);
                        if(p1 == 0 || p2 == 0){
                                p1 |= p2;
                        }
                        else{
                                p1 = lca(p1, p2);
                        }
                        if(dip[p1] > best){
                                best = dip[p1];
                                h = x;
                        }
                }*/
                for(auto p: {get_mn(l, r), get_mx(l, r)}){
                        int x = p.se;
                        int p1 = get(l, x - 1), p2 = get(x + 1, r);
                        if(p1 == 0 || p2 == 0){
                                p1 |= p2;
                        }
                        else{
                                p1 = lca(p1, p2);
                        }
                        if(dip[p1] > best){
                                best = dip[p1];
                                h = x;
                        }
                }
                for(int j = 0; j < 70; j++){
                        used[g[j]] = 0;
                }
                cout << h << " " << best << "\n";
        }
}