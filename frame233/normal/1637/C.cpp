#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef long long ll;
int a[N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	bool flag=1;for(int i=2;i<n;++i)flag&=a[i]==0;
	if(flag)return puts("0"),void();
	flag=0;for(int i=2;i<n;++i)if(a[i]>=2)flag=1;
	if(!flag)return puts("-1"),void();
	if(std::count(a+2,a+n,0)==n-3){
		int x=-1;for(int i=2;i<n;++i)if(a[i])x=a[i];
		if((x%2&&n==3)||x==3)return puts("-1"),void();
		if(x%2)return printf("%d\n",(x+1)/2+1),void();
	}
	ll ans=0;for(int i=2;i<n;++i)ans+=(a[i]+1)/2;
	printf("%lld\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}