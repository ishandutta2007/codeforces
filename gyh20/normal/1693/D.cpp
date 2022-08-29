#include<bits/stdc++.h>
#define re register
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
int t,n,m,a[1000002],A,B,c[1000002],pos,X,typ[1000002],p1,Mx,Mn,stk[1000002],tp,f0[22][1000002],f1[22][1000002];
char s[1000002];
long long ans;
set<int>S[2];
inline bool ck(re int x){
	if(typ[x]==0)return a[x]<*S[0].begin();
	return a[x]>*(--S[1].end());
}
inline int ask(re int x){
	if(x==n)return n;
	if(typ[x]==1&&a[x+1]<*(--S[1].end()))return x;
	if(typ[x]==0&&a[x+1]>*S[0].begin())return x;
	re int y=x+1;
	if(a[x]<a[y])swap(x,y);
	re int l=max(x,y),r=n,pos=min(x,y);
	while(l<=r){
		re int mid=l+r>>1,X=x,Y=y,s=0;
		for(re int i=20;~i;--i)if(f0[i][X]&&f0[i][X]<=mid)s+=1<<i,X=f0[i][X];
		for(re int i=20;~i;--i)if(f1[i][Y]&&f1[i][Y]<=mid)s+=1<<i,Y=f1[i][Y];
		if(s+2==mid-min(x,y)+1)pos=mid,l=mid+1;
		else r=mid-1;
	}return pos;
}
int main(){
	n=read();if(n==1)return puts("1"),0;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i){
		while(tp&&a[i]>=a[stk[tp]])f0[0][stk[tp]]=i,--tp;
		stk[++tp]=i;
	}
	for(re int i=1;i<=tp;++i)f0[0][stk[i]]=1e9;
	tp=0;
	for(re int i=1;i<=n;++i){
		while(tp&&a[i]<=a[stk[tp]])f1[0][stk[tp]]=i,--tp;
		stk[++tp]=i;
	}
	for(re int i=1;i<=tp;++i)f1[0][stk[i]]=1e9;
	for(re int i=1;i<=20;++i)
		for(re int j=1;j+(1<<i)-1<=n;++j){
			if(f0[i-1][j]<=n)f0[i][j]=f0[i-1][f0[i-1][j]];
			else f0[i][j]=1e9;
			if(f1[i-1][j]<=n)f1[i][j]=f1[i-1][f1[i-1][j]];
			else f1[i][j]=1e9;
		}
	
	for(re int i=1;i<n;++i)typ[i]=a[i]<a[i+1];
	S[0].insert(1e9),S[1].insert(0);
	pos=2;S[typ[1]].insert(a[1]);re int p1=1;
	for(re int i=1;i<=n;++i){
		while(pos<n&&ck(pos))S[typ[pos]].insert(a[pos]),++pos;
		ans+=ask(pos)-i+1;
		S[typ[i]].erase(a[i]);
	}
	printf("%lld",ans);
}