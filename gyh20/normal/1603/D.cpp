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
int mu[300002];
int t,n,m,f[32][100002],ans,K,g[100002],h[100002],pri[100002],cnt,phi[100002],S[100002];
char v[100002];
inline int calc(re int l,re int r){
	if(l+l>r)return r-l+1;
	re int s=0;
	for(re int i=l,j;i<=r;i=j+1){
		j=r/(r/i);
		s+=S[r/i]*(j-i+1);
	}
	return s;
}
inline void solve(re int l1,re int r1,re int l2,re int r2){
	re int mid=l2+r2>>1,pos=0,mn=1e18;
	int tt=calc(min(r1,mid-1)+1,mid);
	for(re int i=min(r1,mid-1);i>=l1;--i){
		re int s=g[i]+tt;
		if(s<mn)mn=s,pos=i;
		if(i)tt+=S[mid/i];
	}
	h[mid]=mn;
	if(l2^mid)solve(l1,pos,l2,mid-1);
	if(mid^r2)solve(pos,r1,mid+1,r2);
}
signed main(){
	K=17,n=1e5;
	for(re int i=2;i<=n;++i){
		if(!v[i])pri[++cnt]=i,phi[i]=i-1;
		for(re int j=1;j<=cnt&&i*pri[j]<=n;++j){
			v[i*pri[j]]=1;
			if(i%pri[j]==0){phi[i*pri[j]]=phi[i]*pri[j];break;}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
	S[1]=1;
	for(re int i=2;i<=n;++i)S[i]=S[i-1]+phi[i];
	for(re int i=1;i<=n;++i)f[1][i]=i*(i+1)>>1;
	for(re int i=1;i<=n;++i){
		if(i==1)mu[i]=1;
		for(re int j=i+i;j<=n;j+=i)mu[j]-=mu[i];
	}
	for(re int i=2;i<=17;++i){
		for(re int j=1;j<=n;++j)g[j]=f[i-1][j];
		solve(0,n,1,n);
		for(re int j=1;j<=n;++j)f[i][j]=h[j];
	}
	t=read();
	while(t--){
		n=read(),m=read();
		if(m>K)printf("%lld\n",n);
		else printf("%lld\n",f[m][n]);
	}
}