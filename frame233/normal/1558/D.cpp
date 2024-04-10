#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef std::pair<int,int> pi;
const int N=400005,mod=998244353;
typedef long long ll;
ll fac[N],inv[N],ifac[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
void MAIN(){
	int n,m;read(n,m);
	std::deque<int> v;
	for(int i=1,x,y;i<=m;++i){
		read(x,y);
		int l=0,r=SZ(v),mid;
		while(l<r)mid=(l+r)>>1,mid+v[mid]>=y-1?r=mid:l=mid+1;
		v.insert(v.begin()+l,y-l);
	}
	for(int i=0;i<SZ(v);++i)v[i]+=i;
	v.erase(std::unique(v.begin(),v.end()),v.end());
	printf("%lld\n",C(n+n-1-SZ(v),n));
}
int main(){
	init();
	int _;read(_);
	while(_--)MAIN();
	return 0;
}