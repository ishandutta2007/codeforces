#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2005,mod=1000000007,inv2=(mod+1)/2;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
int f[N][N];
int main(){
	for(int i=1;i<=2000;++i){
		f[i][i]=i;
		for(int j=1;j<i;++j)f[i][j]=1LL*(f[i-1][j-1]+f[i-1][j])*inv2%mod;
	}
	int _;read(_);
	while(_--){
		int n,m,k;read(n,m,k);
		printf("%lld\n",1LL*f[n][m]*k%mod);
	}
	return 0;
}