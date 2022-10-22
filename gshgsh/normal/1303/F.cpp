#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 401
#define MAXM 2000001
int N,M,K,a[MAXN][MAXN],x[MAXM],y[MAXM],c[MAXM],p[MAXM],id[MAXN][MAXN],cnt,f[MAXM*2],tot,ans[MAXM];const int tx[4]={0,1,0,-1},ty[4]={1,0,-1,0};
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}void mrg(int x,int y){int a=getf(x),b=getf(y);if(a!=b)tot--,f[a]=b;}
void upd(int num,int x,int y,int c,int p,int type){if(c==p)return;a[x][y]=c,id[x][y]=++cnt,f[cnt]=cnt;tot=1;For(i,0,3)if(a[x][y]==a[x+tx[i]][y+ty[i]])mrg(id[x][y],id[x+tx[i]][y+ty[i]]);ans[num]+=type*tot;}
void init(){memset(f,0,sizeof(f));cnt=0;For(i,1,N)For(j,1,M)id[i][j]=++cnt,f[cnt]=cnt;For(i,1,N)For(j,1,M)For(k,0,3)if(a[i][j]==a[i+tx[k]][j+ty[k]])mrg(id[i][j],id[i+tx[k]][j+ty[k]]);}
int main()
{
	N=get(),M=get(),K=get();For(i,1,K)x[i]=get(),y[i]=get(),c[i]=get(),p[i]=a[x[i]][y[i]],a[x[i]][y[i]]=c[i];ans[0]=1;memset(a,-1,sizeof(a));For(i,1,N)For(j,1,M)a[i][j]=0;
	init();For(i,1,K)upd(i,x[i],y[i],c[i],p[i],1);init();FOR(i,K,1)upd(i,x[i],y[i],p[i],c[i],-1);For(i,1,K)put(ans[i]+=ans[i-1]),putchar('\n');return 0;
}