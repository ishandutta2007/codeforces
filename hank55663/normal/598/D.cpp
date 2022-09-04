#include<stdio.h>
#include<cstring>
char ma[1010][1010];
int vis[1010][1010];
int ans[1010][1010];
int n,m;
int dfs(int x,int y){
    vis[x][y]=1;
    int sum=0;
    if(x+1<n){
        if(ma[x+1][y]=='*')
            sum++;
        else if(!vis[x+1][y]){
            sum+=dfs(x+1,y);
        }
    }
    else
        sum++;
    if(y+1<m){
        if(ma[x][y+1]=='*')
            sum++;
        else if(!vis[x][y+1]){
            sum+=dfs(x,y+1);
        }
    }
    else
        sum++;
    if(x-1>=0){
        if(ma[x-1][y]=='*')
            sum++;
        else if(!vis[x-1][y]){
            sum+=dfs(x-1,y);
        }
    }
    else
        sum++;
    if(y-1>=0){
        if(ma[x][y-1]=='*')
            sum++;
        else if(!vis[x][y-1]){
            sum+=dfs(x,y-1);
        }
    }
    else
        sum++;
    return sum;
}
void dfs1(int x,int y,int sum){

    ans[x][y]=sum;
    if(x+1<n&&ma[x+1][y]=='.'&&ans[x+1][y]==0){
        dfs1(x+1,y,sum);
    }
    if(y+1<m&&ma[x][y+1]=='.'&&ans[x][y+1]==0){
        dfs1(x,y+1,sum);
    }
    if(x-1>=0&&ma[x-1][y]=='.'&&ans[x-1][y]==0){
        dfs1(x-1,y,sum);
    }
    if(y-1>=0&&ma[x][y-1]=='.'&&ans[x][y-1]==0){
        dfs1(x,y-1,sum);
    }
}
main(){
  int k;
  scanf("%d %d %d",&n,&m,&k);
    memset(ans,0,sizeof(ans));  
    memset(vis,0,sizeof(vis));
  for(int i=0;i<n;i++)
    scanf("%s",ma[i]);
  while(k--){
    int x,y;

    scanf("%d %d",&x,&y);
    x--;y--;
    if(ans[x][y]!=0)
    printf("%d\n",ans[x][y]);
    else{ 
    printf("%d\n",ans[x][y]=dfs(x,y));
    dfs1(x,y,ans[x][y]);
    } 
  }
}