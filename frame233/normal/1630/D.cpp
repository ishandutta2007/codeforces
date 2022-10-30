#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1000005;typedef long long ll;const ll INF=1e18;
int a[N];std::vector<int> v[N];
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)read(a[i]);
	int g=0;for(int i=1,x;i<=m;++i)read(x),g=std::__gcd(g,x);
	for(int i=0;i<g;++i)v[i].clear();
	for(int i=1;i<=n;++i)v[i%g].pb(a[i]);
	for(int i=0;i<g;++i)std::sort(v[i].begin(),v[i].end());
	ll res=0;
	for(int o=0;o<2;++o){
		ll ans=0;
		for(int i=0;i<g;++i){
			ll s=0;for(auto it:v[i])s+=it;
			ll cur=o==0?s:-INF;
			for(int j=0;j<SZ(v[i]);++j){
				s-=v[i][j]*2;
				if(j%2!=o)cur=std::max(cur,s);
			}
			if(cur==-INF){ans=-INF;break;}
			ans+=cur;
		}
		res=std::max(res,ans);
	}
	printf("%lld\n",res);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}