#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll c[1100],s[1100];int len;
void fen(ll x){
	ll t=sqrt(x);
	for(int i=2;i<=t;i++){
		if(x%i==0){
			c[++len]=i;
			while(x%i==0) s[len]++,x/=i;
		}
	}
	if(x>1){
		c[++len]=x;
		s[len]=1;
	}
}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		ll A,B;
		scanf("%lld%lld",&A,&B);
		if(A%B!=0) printf("%lld\n",A);
		else{
			len=0;
			fen(B);
			ll Ans=A;
			for(int i=1;i<=len;i++){
				ll d=1,e=A;
				while(e%B==0) d=d*c[i],e/=c[i];
				if(Ans>d) Ans=d;
			}
			printf("%lld\n",A/Ans);
		}
	}
	return 0;
}