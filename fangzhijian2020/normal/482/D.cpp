#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int read(){
	int a=0,opt=0;char c=getchar();while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
int T,n,fa[100005],h[100005],cnt;
struct edge{int to,next;}e[200005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}int f[100005][2];
void dfs(int x){
	int i,y,del10=0,del01=1,del11=1;f[x][1]=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;dfs(y);int tmp0=f[x][0],tmp1=f[x][1];
		int d11=del11,d01=del01,d10=del10;
		Add(del10,1ll*d11*f[y][1]%mod);
		Add(del01,1ll*d01*f[y][0]%mod);
		Add(del11,1ll*d10*f[y][1]%mod);
		Add(f[x][0],Mod(1ll*tmp0*f[y][0]%mod+1ll*tmp1*f[y][1]%mod));
		Add(f[x][1],Mod(1ll*tmp0*f[y][1]%mod+1ll*tmp1*f[y][0]%mod));
	}
	Add(f[x][0],Mod(f[x][0]-del10+mod));Add(f[x][1],Mod(f[x][1]-del01+mod));
}
int main(){
//	system("fc randomdfs.out randomdfs2.out");
//	freopen("randomdfs.in","r",stdin);
//	freopen("randomdfs.out","w",stdout);
//	T=read()+1;
//	while(--T){
		memset(h,0,sizeof(h));cnt=0;
		memset(f,0,sizeof(f));
		n=read();
		for(int i=2;i<=n;++i){
			fa[i]=read();add(fa[i],i);	
		}
		dfs(1);printf("%d\n",Mod(f[1][0]+f[1][1]));
//	}
	return 0;
}