#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=400005;
typedef long long ll;
ll a[N];
int main(){
	int _;read(_);
	while(_--){
		int n;read(n);
		memset(a,0,(n+3)<<3);
		ll ans=0;
		for(int i=1;i<=n;++i)read(a[i]),ans+=abs(a[i]-a[i-1]);
		ans+=a[n];
		for(int i=1;i<=n;++i)if(a[i]>a[i-1]&&a[i]>a[i+1])ans-=a[i]-std::max(a[i-1],a[i+1]);
		printf("%lld\n",ans);
	}
	return 0;
}