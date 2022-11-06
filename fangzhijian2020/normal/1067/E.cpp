#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353,inv2=499122177;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,h[500005],cnt,x,y,f[500005],ans;
struct edge{int to,next;}e[1000005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
void dfs(int x,int prt){
	int i,y,tmp=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		dfs(y,x);tmp=1ll*tmp*Mod(inv2+1ll*inv2*f[y]%mod)%mod;
	}
	f[x]=Mod(mod+1-tmp);
}
int main(){
	n=read();int tmp=1;
	for(int i=1;i<n;++i){
		x=read();y=read();
		add(x,y);add(y,x);
		tmp=Mod(tmp<<1);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)Add(ans,2ll*f[i]*tmp%mod);
	cout<<ans<<"\n";
	return 0;
}