#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int inv2=499122177;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,m;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second

namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
	int Fast_Pow(int a,int b){
		int res=1;
		while(b){
			if(b&1)res=1ll*res*a%Mod;
			a=1ll*a*a%Mod;
			b>>=1;
		}
		return res;
	}
}using namespace modular;

bool vis[Maxn];
int head[Maxn],v[Maxn],nxt[Maxn],deg[Maxn],tot=0;
inline void add_edge(int s,int e){tot++;deg[s]++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;}
int sg[Maxn];
void dfs(int u){
	if(sg[u]!=-1)return;
	for(int i=head[u];i;i=nxt[i]){
		dfs(v[i]);
	}
	memset(vis,false,sizeof(bool)*(deg[u]+1));
	for(int i=head[u];i;i=nxt[i])vis[sg[v[i]]]=true;
	rep(i,0,deg[u])
		if(!vis[i]){
			sg[u]=i;
			return;
		}
}

int A[Maxn<<1];

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);rd(m);
	memset(sg,-1,sizeof(sg));
	int s,e;
	rep(i,1,m){
		rd(s);rd(e);
		add_edge(s,e);
	}
	rep(i,1,n)
		if(sg[i]==-1)dfs(i);
	rep(i,1,n){
		A[sg[i]]++;
	}
	int t=Fast_Pow(n+1,Mod-2);
	rep(i,0,(1<<17)-1)A[i]=mul(A[i],t);
	per(i,16,0)
		for(int j=0;j<(1<<17);j+=(1<<(i+1)))
			for(int k=0;k<(1<<i);++k){
				int x=A[j+k],y=A[j+k+(1<<i)];
				A[j+k]=dec(x,y);
				A[j+k+(1<<i)]=add(x,y);
			}
	rep(i,0,(1<<17)-1)A[i]=Fast_Pow(dec(1,A[i]),Mod-2);
	rep(i,0,16)
		for(int j=0;j<(1<<17);j+=(1<<(i+1)))
			for(int k=0;k<(1<<i);++k){
				int x=A[j+k],y=A[j+k+(1<<i)];
				A[j+k]=add(x,y);A[j+k]=mul(A[j+k],inv2);
				A[j+k+(1<<i)]=dec(y,x);A[j+k+(1<<i)]=mul(A[j+k+(1<<i)],inv2);
			}
	int res=mul(t,A[0]);
	res=dec(1,res);
	printf("%d\n",res);
	return 0;
}