#include <cstdio>
#include <cstring>

const int N = 1000;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, m, f[N][N], l[N * N];
bool v[10], h[N][N];
char g[N][N + 1];

bool valid(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int i, int j, int a){
    if(valid(i, j) && f[i][j] == a && !h[i][j]){
        h[i][j] = true;
        for(int k = 0; k < 4; ++ k)
            if(valid(i + dx[k], j + dy[k]) && f[i + dx[k]][j + dy[k]] != -1 && l[f[i + dx[k]][j + dy[k]]] != -1)
                v[l[f[i + dx[k]][j + dy[k]]]] = true;
        for(int k = 0; k < 4; ++ k)
            dfs(i + dx[k], j + dy[k], a);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++ i)
        scanf("%s", g[i]);
    memset(f, -1, sizeof(f));
    int cnt = 0;
    for(int i = 0; i < n; ++ i)
        for(int j = 1; j < m; ++ j)
            if(g[i][j - 1] != '#' && g[i][j] != '#'){
                g[i][j - 1] = g[i][j] = '#';
                f[i][j - 1] = f[i][j] = cnt ++;
            }
    for(int i = 1; i < n; ++ i)
        for(int j = 0; j < m; ++ j)
            if(g[i - 1][j] != '#' && g[i][j] != '#'){
                g[i - 1][j] = g[i][j] = '#';
                f[i - 1][j] = f[i][j] = cnt ++;
            }
    for(int i = 0; i < n; ++ i)
        for(int j = 0; j < m; ++ j)
            if(g[i][j] == '.'){
                for(int k = 0; k < 4; ++ k)
                    if(valid(i + dx[k], j + dy[k]) && f[i + dx[k]][j + dy[k]] != -1){
                        g[i][j] = '#';
                        f[i][j] = f[i + dx[k]][j + dy[k]];
                        break;
                    }
                if(f[i][j] == -1){
                    printf("-1\n");
                    return 0;
                }
            }
    memset(h, 0, sizeof(h));
    memset(l, -1, sizeof(l));
    for(int i = 0; i < n; ++ i)
        for(int j = 0; j < m; ++ j)
            if(f[i][j] != -1 && l[f[i][j]] == -1){
                memset(v, 0, sizeof(v));
                dfs(i, j, f[i][j]);
                l[f[i][j]] = 0;
                while(v[l[f[i][j]]])
                    l[f[i][j]] += 1;
            }
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j)
            printf("%c", f[i][j] == -1? '#': '0' + l[f[i][j]]);
        printf("\n");
    }
    return 0;
}