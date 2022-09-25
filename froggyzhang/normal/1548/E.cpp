#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mx=200000;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,X,a[N],b[N],_a[N],_b[N],ta[N],tb[N],pa[N],pb[N];
ll ans;
class BIT{
public:
	int b[N];
	inline int lowbit(int x){return x&(-x);}
	inline void Add(int x,int d){
		while(x<=mx)b[x]+=d,x+=lowbit(x);
	}	
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
class ST_table{
public:
	int f[20][N],lg[N];
	void init(int *a,int n){
		for(int i=1;i<=n;++i){
			f[0][i]=a[i];
		}
		for(int j=1;j<=19;++j){
			for(int i=1;i+(1<<j)-1<=n;++i){
				f[j][i]=max(f[j-1][i],f[j-1][i+(1<<j-1)]);
			}
		}
		for(int i=2;i<=n;++i){
			lg[i]=lg[i>>1]+1;
		}
	}
	inline int Query(int l,int r){
		int k=lg[r-l+1];
		return max(f[k][l],f[k][r-(1<<k)+1]);	
	}
}Ta,Tb;
void work(int *a,int *ta,int n,ST_table T){
	static int tl[N],tr[N],st[N],top;
	top=0;
	for(int i=1;i<=n;++i){
		while(top&&a[i]<a[st[top]])--top;
		tl[i]=st[top];
		st[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;--i){
		while(top&&a[i]<a[st[top]])--top;
		tr[i]=st[top];
		st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		ta[i]=min(tl[i]?T.Query(tl[i],i):X+1,tr[i]?T.Query(i,tr[i]):X+1);
	}
}
int main(){
	n=read(),m=read(),X=read();
	for(int i=1;i<=n;++i){
		_a[i]=read();
		pa[i]=i;	
	}
	for(int i=1;i<=m;++i){
		_b[i]=read();
		pb[i]=i;
	}
	sort(pa+1,pa+n+1,[&](int i,int j){return _a[i]<_a[j];});
	sort(pb+1,pb+m+1,[&](int i,int j){return _b[i]<_b[j];});
	for(int i=1;i<=n;++i)a[pa[i]]=i;
	for(int i=1;i<=m;++i)b[pb[i]]=i;
	Ta.init(_a,n),Tb.init(_b,m);
	work(a,ta,n,Ta),work(b,tb,m,Tb);
	sort(pb+1,pb+m+1,[&](int i,int j){return tb[i]>tb[j];});
	for(int i=n,j=m;i>=0;--i){
		while(j&&(!i||_a[pa[i]]+tb[pb[j]]<=X)){
			ans+=B.Ask(_b[pb[j]]);--j;
		}
		B.Add(max(1,X-ta[pa[i]]+1),1);
		B.Add(max(1,X-_a[pa[i]]+1),-1);
	}
	printf("%lld\n",ans);
	return 0;
}