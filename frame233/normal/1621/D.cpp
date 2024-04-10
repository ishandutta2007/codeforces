#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=505;typedef long long ll;
int c[N][N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=2*n;++i)for(int j=1;j<=2*n;++j)read(c[i][j]);
	ll ans=0;for(int i=n+1;i<=2*n;++i)for(int j=n+1;j<=2*n;++j)ans+=c[i][j];
	printf("%lld\n",ans+std::min({c[n][n+1],c[n+1][n],c[n*2][n],c[n][n*2],c[1][n+1],c[1][n*2],c[n*2][1],c[n+1][1]}));
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}