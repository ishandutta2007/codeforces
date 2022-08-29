#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct heap{
	priority_queue<int>q,d;
	inline void insert(re int x){q.push(x);}
	inline void del(re int x){d.push(x);}
	inline int first(){
		while(!d.empty()&&q.top()==d.top())q.pop(),d.pop();
		return q.top();
	}
}H;
int n,a[1200002],m,b[1200002],ans,t,tr[1200002],stk[1200002],tp,val[1200002],f[1200002];
char s[1000002];
priority_queue<int>q;
inline void cg(re int p,re int l,re int r,re int x,re int y){
	if(l==r){
		tr[p]=y;
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)cg(p<<1,l,mid,x,y);
	else cg(p<<1|1,mid+1,r,x,y);
	tr[p]=max(tr[p<<1],tr[p<<1|1]);
}
inline int ask(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y)return tr[p];
	re int mid=l+r>>1,s=-1e18;
	if(x<=mid)s=max(s,ask(p<<1,l,mid,x,y));
	if(y>mid)s=max(s,ask(p<<1|1,mid+1,r,x,y));
	return s;
}
signed main(){
	n=read();memset(tr,-127,sizeof(tr));
	cg(1,0,n,0,0);
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i)b[i]=read();
	for(re int i=1;i<=n;++i){
		while(tp&&a[i]<=a[stk[tp]]){
			H.del(val[stk[tp]]);
			--tp;
		}
		H.insert(val[i]=(ask(1,0,n,stk[tp],i-1)+b[i]));
		f[i]=H.first();
		stk[++tp]=i;
		cg(1,0,n,i,f[i]);
	}
	printf("%lld",f[n]);
}