#include<bits/stdc++.h>
#define re register
#define ll long long
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
int t,n,m,a[1000002],ans,A,B,sum[2000004],lst[2000004],nxt[2000004],N=2e6;
char s[1000002];
inline int ask(re ll l,re ll r){
	if(l>r)return 0;
	if(r<0)return 0;
	if(l>N)return 0;
	if(r>N)r=N;
	if(l<0)l=1;
	return sum[r]-sum[l-1];
}
inline int find1(re ll l,re ll r){
	if(l<0)l=1;
	if(l>N)return 0;
	if(nxt[l]<=r)return nxt[l];
	return 0;
}
inline int find2(re ll l,re ll r){
	if(r<0)return 0;
	if(r>N)r=N;
	if(lst[r]>=l)return lst[r];
	return 0;
}
signed main(){
	n=read(),N=2e6+1;
	for(re int i=1;i<=n;++i)a[i]=read(),++sum[a[i]];
	for(re int i=1;i<=N;++i)lst[i]=sum[i]?i:lst[i-1];
	for(re int i=N;i;--i)nxt[i]=sum[i]?i:nxt[i+1];
	for(re int i=1;i<=N;++i)sum[i]+=sum[i-1];
	for(re int i=1;i<=2000001;++i){
		re ll l=1ll*i*i-a[1],r=1ll*i*(i+1)-a[1];
		if(r<0)continue;
		if(l<0)l=0;
		re ll L=l,R=r;
		re bool ia=1;
		re int nn=0; 
		for(re int j=i;j<=2000001;++j){
			re ll nl=1ll*j*j,nr=1ll*j*(j+1);
			++nn;
			if(ask(1ll*(j-1)*j-l+1,nl-r-1)){
				ia=0;
				break;
			}
			re int p1=find1(nl-r,nr-l),p2=find2(nl-r,nr-l);
			if(p1)L=max(L,nl-p1);
			if(p2)R=min(R,nr-p2);
			if(a[n]+r<nl)break;
		}
		if(ia&&L<=R){
			printf("%lld\n",L);
			return 0;
		}
	}
	
}