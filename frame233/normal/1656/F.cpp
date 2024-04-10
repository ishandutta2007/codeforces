#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;typedef __int128 LL;
struct edge{int u,v;ll w;inline bool operator < (const edge &o)const{return w<o.w;}}e[N];
int n,a[N];ll b[N];
LL calc(ll t){
	for(int i=1;i<=n;++i)b[i]=a[i]+t;
	int mn=std::min_element(b+1,b+n+1)-b,mx=std::max_element(b+1,b+n+1)-b;LL ans=0;
	for(int i=1;i<=n;++i)if(i!=mn&&i!=mx){
		if(b[i]>0)ans+=1LL*b[mn]*b[i]-1LL*t*t;
		else ans+=1LL*b[mx]*b[i]-1LL*t*t;
	}
	ans+=1LL*b[mn]*b[mx]-1LL*t*t;
	return ans;
}
void MAIN(){
	read(n);for(int i=1;i<=n;++i)read(a[i]);
	ll l=-1e9,r=1e9,mid;
	if(calc(l)>calc(l+1)||calc(r)>calc(r-1))return puts("INF"),void();
	while(r-l>=3)mid=l+(r-l)/2,calc(mid)>calc(mid+1)?r=mid+1:l=mid;
	LL ans=-4e18;for(int i=l;i<=r;++i)ans=std::max(ans,calc(i));
	printf("%lld\n",(ll)ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}