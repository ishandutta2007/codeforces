#include<cstdio>
long long n,m,v[100002],T,S,oo;
signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&S,&T),oo=n*T,--S;
	for(long long i=T;i;--i){
		if(i%n==T%n){
			if(v[S])i%=(v[S]-i);
			v[S]=i;
		}
		if(S<m)S=(S+i)%n;
		else S=(S-i+oo)%n;
	}
	printf("%lld",S+1);
}