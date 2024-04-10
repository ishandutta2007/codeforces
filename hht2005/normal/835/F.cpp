#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int h[2*N],q[2*N],hea[N],nxt[2*N],to[2*N],w[2*N],in[N],tot=1,hd,b;
long long val1[N],val2[N],Dis[N];
long long f[N],s[2*N],ans=1e18,Max;
inline int read() {
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+ch-'0',ch=getchar());
	return x*f;
}
void add(int x,int y,int v) {
	nxt[++tot]=hea[x];
	hea[x]=tot;
	to[tot]=y;
	w[tot]=v;
}
void dfs(int x,int t) {
	in[x]=1;
	for(int i=hea[x];i;i=nxt[i]) {
		if((i^1)==t)continue;
		int y=to[i];
		if(in[y]==1) {
			b=y;
			in[x]=2;
			h[++hd]=x;
			s[hd]=w[i];
		}
		else if(!in[y]) {
			dfs(y,i);
			if(in[y]==2&&y!=b) {
				in[x]=2;
				h[++hd]=x;
				s[hd]=s[hd-1]+w[i];
			}
		}
	}
}
void getf(int x,int fa) {
	for(int i=hea[x];i;i=nxt[i]) {
		int y=to[i];
		if(in[y]==2||y==fa)continue;
		getf(y,x);
		Max=max(Max,f[x]+w[i]+f[y]);
		f[x]=max(f[x],w[i]+f[y]);
	}
}
signed main() {
	int n=read(),x,y,v;
	for(int i=1;i<=n;i++) {
		x=read(),y=read(),v=read();
		add(x,y,v);
		add(y,x,v);
	}
	b=hd=Max=0;
	dfs(1,0);
	for(int i=1;i<=hd;i++)
		getf(h[i],0);
	val2[0]=val1[hd+1]=-1e18;
	for(int i=1;i<=hd;i++) {
		val1[i]=f[h[i]]-s[i];
		val2[i]=f[h[i]]+s[i];
	}
	for(int i=1,Max=-1e18,Ans=0;i<=hd;i++) {
		Ans=max(Ans,Max+val2[i]);
		Dis[i]=Ans;
		Max=max(Max,val1[i]);
	}
	for(int i=hd,Max=-1e18,Ans=0;i>=1;i--) {
		Ans=max(Ans,Max+val1[i]);
		Dis[i-1]=max(Dis[i-1],Ans);
		Max=max(Max,val2[i]);
	}
	for(int i=1;i<=hd;i++)val2[i]=max(val2[i],val2[i-1]);
	for(int i=hd;i>=1;i--)val1[i]=max(val1[i],val1[i+1]);
	for(int i=1;i<=hd;i++) {
		Dis[i]=max(Dis[i],val2[i]+val1[i+1]+s[hd]);
		ans=min(ans,Dis[i]);
	}
	ans=max(ans,Max);
	printf("%lld\n",ans);
	return 0;
}