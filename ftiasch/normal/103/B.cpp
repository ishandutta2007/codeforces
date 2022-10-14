#include <cstdio>
#include <cstring>

const int N = 222;

int n, m, parent[N], count[N][N];

int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

int main(){
    scanf("%d%d", &n, &m);
    if(n != m){
        printf("NO\n");
        return 0;
    }
    for(int i = 1; i <= n; ++ i){
        parent[i] = i;
    }
    memset(count, 0, sizeof(count));
    for(int i = 1; i <= m; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        count[x][y] += 1;
        count[y][x] += 1;
        if(find(x) != find(y)){
            parent[find(x)] = find(y);
        }
    }
    for(int i = 2; i <= n; ++ i){
        if(find(i) != find(1)){
            printf("NO\n");
            return 0;
        }
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            if(count[i][j] > 1){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("FHTAGN!\n");
    return 0;
}