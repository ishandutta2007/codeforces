#include <stdio.h>

int str[505],adj[505][505],n,m,u,v;
char dic[4] = {'0','a','b','c'};

int main() {

    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++) {
        scanf("%d %d",&u,&v);
        adj[u][v] = adj[v][u] = 1;
    }

    int flag = 0;
    for(int i=1;i<=n;i++) {
        int edges = 0;
        adj[i][i] = 1;

        for(int j=1;j<=n;j++) {
            edges += adj[i][j];
        }

        if(edges == n) str[i] = 2;
        else if(flag == 0) {
            for(int j=1;j<=n;j++) {
                if(!str[j]) str[j] = adj[i][j]?1:3;
            }
            flag = 1;
        }
    }

    int flag2 = 1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(adj[i][j] && str[i]*str[j]==3) flag2 = 0;
            else if(!adj[i][j] && str[i]*str[j]!=3) flag2 = 0;
        }
    }

    if(flag2 == 1) {
        printf("Yes\n");
        for(int i=1;i<=n;i++) {
            printf("%c",dic[str[i]]);
        }
    }
    else printf("No\n");
    return 0;
}