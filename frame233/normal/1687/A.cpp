#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
ll a[N];
inline ll f(ll x){return x*(x+1)/2;}
void MAIN(){
	int n,k;read(n,k);
	for(int i=1;i<=n;++i)read(a[i]),a[i]+=a[i-1];
	if(k>n)printf("%lld\n",a[n]+f(k-1)-f(k-n-1));
	else{
		ll ans=0;for(int i=k;i<=n;++i)ans=std::max(ans,a[i]-a[i-k]);
		ans+=f(k-1);printf("%lld\n",ans);
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}