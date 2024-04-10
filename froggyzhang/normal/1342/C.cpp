#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,a,b,Q,s[N],lcm;
int _gcd(int a,int b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
inline ll Solve(ll x){
	return x-(s[lcm]*(x/lcm)+s[x%lcm]);
}
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),Q=read();
		int g=_gcd(a,b);
		lcm=a*b/g;
		for(int i=1;i<=lcm;++i){
			s[i]=s[i-1]+((i%a%b)==(i%b%a));
		}
		while(Q--){
			ll l=read(),r=read();
			printf("%I64d ",Solve(r)-Solve(l-1));
		}
		printf("\n");
	}
	return 0;
}