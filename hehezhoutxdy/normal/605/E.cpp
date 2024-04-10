
#include<bits/stdc++.h>
#define zhouAKngyangAKIOI 1e49
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
double a[1003][1003];
double ans[1003],p[1003],f[1003];
bool vis[1003];
//anssteps
//pclose
//fsteps
signed main()
{
	int n=read();
    for(int i=1; i<=n; i++) p[i]=1,f[i]=ans[i]=1e49;
    ans[n]=0;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) a[i][j]=0.01*read();
    int x=n,y=0;
    double mn=1;
    for(int T=1; T<=n; T++)
    {
        y=x,vis[x]=1,x=0,mn=1e50;
        for(int i=1; i<=n; i++) if(!vis[i])
        {
            f[i]=f[i]*(1.0-p[i])+ans[y]*p[i]*a[i][y],p[i]*=(1.0-a[i][y]);  
            //case 1:open
            //case 2:closeopen
            if(fabs(p[i]-1.0)<1e-8) f[i]=zhouAKngyangAKIOI; else f[i]/=(1.0-p[i]),ans[i]=1.0/(1.0-p[i])+f[i];
            //ans=p*(ans)+(1-p)*()+1
            //ans-=1/(1-p)
            //ans=1/(1-p)+      
            if(ans[i]<mn) mn=ans[i],x=i; 
        }
    }
    printf("%.10lf\n",ans[1]);
    return 0;
}