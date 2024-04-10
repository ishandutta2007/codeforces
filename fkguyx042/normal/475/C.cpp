#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <algorithm>  
  
using namespace std;  
  
const int maxn=1100;  
const int INF=0x3f3f3f3f;  
  
char mp[maxn][maxn];  
int n,m,sum[maxn][maxn];  
int ans=INF;  
  
int area(int x1,int y1,int x2,int y2)  
{  
    return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];  
}  
  
int dfs(int x,int y,int wx,int wy)  
{  
    if(area(x,y+1,x+wx-1,y+wy)==wx*wy) return wx+dfs(x,y+1,wx,wy);  
    if(area(x+1,y,x+wx,y+wy-1)==wx*wy) return wy+dfs(x+1,y,wx,wy);  
    return wx*wy;     
}  
  
int main()  
{  
    scanf("%d%d",&n,&m);  
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);  
    bool flag=false;  
    int px=-1,py=-1;  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=1;j<=m;j++)  
        {  
            int t=0;  
            if(mp[i][j]=='X')  
            {  
                if(flag==false)  
                {  
                    flag=true; px=i; py=j;  
                }  
                t=1;  
            }     
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t;  
        }  
    }  
      
    int temp=py;  
    for(;temp<=m;temp++) if(mp[px][temp]!='X') break;  
    int leny=temp-py;  
    int lenx;  
    for(int i=px;i<=n;i++)  
    {  
        if(mp[i][py]!='X') break;  
        lenx=i-px+1;  
        if(dfs(px,py,lenx,leny)==sum[n][m])  
        {  
            ans=min(ans,lenx*leny);  
        }  
    }  
    temp=px;  
    for(;temp<=n;temp++) if(mp[temp][py]!='X') break;  
    lenx=temp-px;  
    for(int i=py;i<=m;i++)  
    {  
        if(mp[px][i]!='X') break;  
        leny=i-py+1;  
        if(dfs(px,py,lenx,leny)==sum[n][m])  
        {  
            ans=min(ans,lenx*leny);  
        }  
    }  
  
    if(ans==INF) ans=-1;  
    printf("%d\n",ans);  
    return 0;  
}