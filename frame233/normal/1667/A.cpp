#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=5005;typedef long long ll;
ll a[N],b[N];
ll solve(const std::vector<ll> &vec){
	if(vec.empty())return 0;
	ll last=1,ans=1;
	for(int i=1;i<SZ(vec);++i){
		last=last*vec[i-1]/vec[i]+1;
		ans+=last;
	}
	return ans;
}
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	ll ans=1e18;
	for(int p=1;p<=n;++p){
		std::vector<ll> vec;for(int i=p+1;i<=n;++i)vec.pb(a[i]);
		ll tmp=solve(vec);
		vec.clear();for(int i=p-1;i>=1;--i)vec.pb(a[i]);
		tmp+=solve(vec);
		ans=std::min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}