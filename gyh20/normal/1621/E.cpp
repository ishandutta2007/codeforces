#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,ans,tg[500002],mn[500002],a[500002];
long long sum[200002];
inline void Add(re int x,re int y){
	tg[x]+=y,mn[x]+=y;
}
inline void pd(re int x){
	if(tg[x]){
		Add(x<<1,tg[x]),Add(x<<1|1,tg[x]);
		tg[x]=0;
	}
}
inline void add(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y)return Add(p,z);
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,z);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,z);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
inline void Ins(re int x,re int y,re int z){
	re int l=1,r=n,pos=n+1;
	while(l<=r){
		re int mid=l+r>>1;
		if(a[mid]*x>=y)pos=mid,r=mid-1;
		else l=mid+1;
	}
	add(1,1,n+1,1,pos,z);
}
vector<int>V[200002];
signed main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n*4+4;++i)tg[i]=mn[i]=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);
		for(re int i=n;i;--i)add(1,1,n+1,1,i,1);
		for(re int i=1;i<=m;++i){
			re int x=read();V[i].clear();
			sum[i]=0;
			while(x--)V[i].push_back(read());
			for(re int j=0;j<V[i].size();++j)sum[i]+=V[i][j];
			Ins(V[i].size(),sum[i],-1);
		}
		for(re int i=1;i<=m;++i){
			Ins(V[i].size(),sum[i],1);
			for(re int j=0;j<V[i].size();++j){
				Ins(V[i].size()-1,sum[i]-V[i][j],-1);
				if(mn[1]<0)putchar('0');else putchar('1');
				Ins(V[i].size()-1,sum[i]-V[i][j],1);
			}
			Ins(V[i].size(),sum[i],-1);
		}
		puts("");
	}
}