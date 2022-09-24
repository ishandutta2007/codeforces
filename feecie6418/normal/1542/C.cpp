#include<bits/stdc++.h>
#define int long long
#define re register
using namespace std;
int t,n;
const int M=1e9+7;
inline int gcd(re int x,re int y){
	return y?gcd(y,x%y):x;
}
inline int LCM(re int x,re int y){
	return x/gcd(x,y)*y;
}
signed main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		re int G=1,ans=0;
		for(re int i=1;G<=n;++i){
			G=LCM(G,i);
			if(G>n)break;
			ans+=n/G;
		}
		printf("%lld\n",(ans+n)%M);
	}
}