#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 1550;
const int mod = 998244353;

using namespace std;

int n;
int st[N];
int en[N];
int p[N];
vector < int > edge[N];
int a[N][N];
int f[N];
int nxt[N], dead[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
unordered_map < int, vector < int > > V[N];
int d[N][N];

int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        scanf("%d", &a[i][j]);
                }
                st[i] = en[i] = i;
                p[i] = i;
                f[i] = rng();
        }
        vector < int > v;
        for(int i = 1; i <= n; i++){
                v.clear();
                for(int j = 1; j <= n; j++){
                        if(i != j) v.push_back(j);
                }
                sort(v.begin(), v.end(), [&](int x, int y){
                        return a[i][x] < a[i][y];
                });
                long long cur = f[i];
                for(int j = 1; j <= n; j++){
                        V[j][cur].push_back(i);
                        if(j < n){
                                cur ^= f[v[j - 1]];
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(auto P: V[i]){
                        if(P.se.size() != i){
                                continue;
                        }
                        int x = P.se[0];
                        for(int y: P.se){
                                if(get(x) == get(y)) continue;
                                x = get(x);
                                int py = get(y);
                                nxt[en[x]] = st[py];
                                dead[st[py]] = 1;
                                p[py] = x;
                                en[x] = en[py];
                        }
                        edge[st[get(x)]].push_back(i);
                }
        }
        vector < int > ord;
        for(int i = 1; i <= n; i++){
                if(!dead[i]){
                        ord.push_back(i);
                }
        }
        assert((int)ord.size() == 1);
        while(ord.size() < n){
                ord.push_back(nxt[ord.back()]);
        }

        d[0][0] = 1;
        for(int i = 0; i < n; i++){
                for(int k = 0; k < n; k++){
                        if(!d[i][k]) continue;
                        for(int x: edge[ord[i]]){
                                add(d[i + x][k + 1], d[i][k]);
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                printf("%d ", d[n][i]);
        }
}