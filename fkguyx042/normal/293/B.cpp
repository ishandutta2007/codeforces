#include<stdio.h>
#define N 11
using namespace std;
const int P=1e9+7;
int a[N][N],used[N],vis[N][N];
int bit[1<<N],n,m,c,i,j;
int DFS(int x,int y){
    if (y>m) ++x,y=1;if (x>n) return 1;
    vis[x][y]=vis[x-1][y]|vis[x][y-1];int ret=0,num=-1;
    for (int T=(~vis[x][y])&((1<<c)-1);T;T-=T&-T){
        int k=bit[T&-T];
        if (a[x][y]>=0&&a[x][y]!=k) continue;
        vis[x][y]^=1<<k;
        if ((++used[k])==1){
            if (num==-1)
                num=DFS(x,y+1);
            ret+=num;
      }else ret+=DFS(x,y+1);
      if (ret>=P) ret-=P;used[k]--;
      vis[x][y]^=1<<k;
  }return ret;
}
int main(){
    scanf("%d%d%d",&n,&m,&c);
    if (c<n+m-1) return puts("0"),0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if ((--a[i][j])>=0) 
                ++used[a[i][j]];
      }
    for (i=1;i<=c;i++) bit[1<<i]=i;
    printf("%d\n",DFS(1,1));
}