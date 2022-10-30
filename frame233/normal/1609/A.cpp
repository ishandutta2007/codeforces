#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;
ll a[25],b[25];
void MAIN(){
	int n;read(n);for(int i=1;i<=n;++i)read(a[i]);
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)b[j]=a[j];
		for(int j=1;j<=n;++j)if(i!=j){
			while(b[j]%2==0)b[j]/=2,b[i]*=2;
		}
		ll sum=0;for(int j=1;j<=n;++j)sum+=b[j];
		ans=std::max(ans,sum);
	}
	printf("%lld\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}