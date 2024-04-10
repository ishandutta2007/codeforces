#include <bits/stdc++.h>
using namespace std;
#define MAX 200
int mat[MAX][MAX];
int use[MAX*MAX];
int group[MAX][MAX];
int M, N;
set<int> graph[MAX*MAX];
int abs(int x){
    return x>0?x:-x;
}
void fill(int x, int y, int cnt){
    if(x==0||x==N+1||y==0||y==M+1||group[x][y]) return;
    group[x][y]=cnt;
    if(abs(mat[x][y]-mat[x-1][y])==1) fill(x-1, y, cnt);
    if(abs(mat[x][y]-mat[x+1][y])==1) fill(x+1, y, cnt);
    if(abs(mat[x][y]-mat[x][y-1])==1) fill(x, y-1, cnt);
    if(abs(mat[x][y]-mat[x][y+1])==1) fill(x, y+1, cnt);
}
void dfs(int x, int c){
    if(use[x]){
        return;
    }
    use[x]=c;
    if(graph[x].empty()) return;
    set<int>::iterator it;
    for(it=graph[x].begin();it!=graph[x].end();it++){
        dfs(*it, 3-c);
    }
}
int main(void){
    int T;
    scanf("%d", &T);
    while(T>0){
        T--;
        scanf("%d %d", &N, &M);
        int i, j;
        for(i=1;i<=(M+1)*(N+1);i++){
            graph[i].clear();
            use[i]=0;
        }
        for(i=1;i<=N;i++){
            for(j=1;j<=M;j++){
                group[i][j]=0;
                scanf("%d", &mat[i][j]);
            }
        }
        int cnt=0;
        for(i=1;i<=N;i++){
            for(j=1;j<=M;j++){
                if(group[i][j]==0){
                    fill(i, j, ++cnt);
                }
            }
        }
        for(i=1;i<=N;i++){
            for(j=1;j<=M;j++){
                if(mat[i][j]-mat[i-1][j]==0){
                    graph[group[i][j]].insert(group[i-1][j]);
                    graph[group[i-1][j]].insert(group[i][j]);
                }
                if(mat[i][j]-mat[i+1][j]==0){
                    graph[group[i][j]].insert(group[i+1][j]);
                    graph[group[i+1][j]].insert(group[i][j]);
                }
                if(mat[i][j]-mat[i][j-1]==0){
                    graph[group[i][j]].insert(group[i][j-1]);
                    graph[group[i][j-1]].insert(group[i][j]);
                }
                if(mat[i][j]-mat[i][j+1]==0){
                    graph[group[i][j]].insert(group[i][j+1]);
                    graph[group[i][j+1]].insert(group[i][j]);
                }
            }
        }
        for(i=1;i<=cnt;i++){
            if(use[i]==0) dfs(i, 1);
        }
        for(i=1;i<=N;i++){
            for(j=1;j<=M;j++){
                printf("%d ", mat[i][j]+use[group[i][j]]-1);
            }
            printf("\n");
        }
    }
}