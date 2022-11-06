#include<bits/stdc++.h>
using namespace std;
const int Mxdt=100000,N=200000,mod=998244353;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
char pc(char c,bool opt){
	return (opt||putchar(c)),0;static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (opt||(*p1++=c,p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10^48,0);
}
void printnum(int x,char c){
	if(x<0)pc('-',0),x=-x;
	print(x);pc(c,0);
}
int T,n,x,y,X,Y,vis[200005],prime[200005],tot,inv[200005],num[200005],Max[200005],ans,sum,tmp;
int h[200005],cnt,q[4000005],top,d[200005];vector<int>v[200005];
struct edge{int to,next,X,Y;}e[400005];
void add(int x,int y,int X,int Y){
	e[++cnt]=(edge){y,h[x],X,Y};h[x]=cnt;
}
void solve(int X,int Y){
	int now=X;
	for(int x:v[X]){
		while(now%prime[x]==0){
			now/=prime[x];--num[x];
		}
	}
	now=Y;
	for(int x:v[Y]){
		while(now%prime[x]==0){
			now/=prime[x];++num[x];
			if(num[x]>Max[x]){
				tmp=1ll*tmp*prime[x]%mod;
				Max[x]=max(Max[x],num[x]);
				q[++top]=x;
			}
		}
	}
}
void dfs(int x){
	int i,y;vis[x]=1;sum=(sum+d[x])%mod;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(vis[y])continue;
		solve(e[i].Y,e[i].X);
		d[y]=1ll*d[x]*inv[e[i].X]%mod*e[i].Y%mod;
		dfs(y);
		solve(e[i].X,e[i].Y);
	}
}
int main(){
	inv[1]=1;for(int i=2;i<=N;++i)inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=N;++i){
		if(!vis[i])prime[++tot]=i;
		for(int j=1;j<=tot;++j){
			if(i*prime[j]>N)break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1;i<=tot;++i){
		for(int j=prime[i];j<=N;j+=prime[i]){
			v[j].push_back(i);
		}
	}
	T=read()+1;
	while(--T){
		n=read();ans=0;cnt=0;
		for(int i=1;i<=n;++i)h[i]=vis[i]=num[i]=Max[i]=0;
		for(int i=1;i<n;++i){
			x=read();y=read();X=read();Y=read();
			add(x,y,X,Y);add(y,x,Y,X);
		}
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				sum=0;tmp=1;
				d[i]=1;dfs(i);
				ans=(ans+1ll*sum*tmp%mod)%mod;
				while(top){
					Max[q[top]]=0;--top;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return pc(0,1);
}