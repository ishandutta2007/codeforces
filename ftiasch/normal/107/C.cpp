#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 16;

int n, m, t, p[N], r[N], im[N], ts[1 << N], one[1 << N];
bool g[N][N], o[N];
long long y, dp[1 << N];

long long dfs(int mask){
    if(mask == (1 << n) - 1){
        return 1;
    }
    if(ts[mask] != t){    
        int i = one[mask];
        if(r[i] == -1){
            dp[mask] = 0;
            for(int j = 0; j < n; ++ j){ // place
                if(not o[j] and (mask & (1 << j)) == 0 and (mask & im[j]) == im[j]){
                   dp[mask] += dfs(mask | (1 << j));
                }
            }
        }else{
            dp[mask] = 0;
            if((mask & im[r[i]]) == im[r[i]]){
                dp[mask] += dfs(mask | (1 << r[i]));
            }
        }
        ts[mask] = t;
    }
    return dp[mask];
}

int main(){
    //freopen("C.in", "r", stdin);
    cin >> n >> y >> m;
    memset(g, 0, sizeof(g));
    for(int i = 0; i < m; ++ i){
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u][v] = true;
    }
    for(int k = 0; k < n; ++ k){
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < n; ++ j){
                g[i][j] = g[i][j] or (g[i][k] and g[k][j]);
            }
        }
    }
    memset(im, 0, sizeof(im));
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            if(i != j and g[j][i]){
                im[i] |= (1 << j);
            }
        }
    }
    for(int i = 0; i < n; ++ i){
        for(int j = i + 1; j < n; ++ j){
            if(g[i][j] and g[j][i]){
                printf("The times have changed\n");
                return 0;
            }
        }
    }
    one[0] = 0;
    for(int i = 1; i < (1 << n); ++ i){
        one[i] = one[i >> 1] + (i & 1);
    }
    y -= 2001;
    t = 0;
    memset(ts, -1, sizeof(ts));
    memset(r, -1, sizeof(r)); // the i-th number should place
    memset(o, 0, sizeof(o)); // if the i-th place occupy
    long long temp = dfs(0);
    if(y >= temp){
        printf("The times have changed\n");
        return 0;
    }
    for(int i = 0; i < n; ++ i){
        //printf("-- %d\n", i);
        o[i] = true;
        for(int j = 0; j < n; ++ j){
            if(r[j] == -1){
                r[j] = i;
                t += 1;
                long long temp = dfs(0);
                if(y < temp){
                    //printf("-- %d %d\n", i, j);
                    p[i] = j;
                    break;
                }else{
                    y -= temp;
                }
                r[j] = -1;
            }
        }
    }
    for(int i = 0; i < n; ++ i){
        printf("%d%c", p[i] + 1, i == n - 1? '\n': ' ');
    }
    return 0;
}