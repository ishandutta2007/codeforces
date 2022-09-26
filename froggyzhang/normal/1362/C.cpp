#include<cstring>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int T;
ll n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		ll ans=0;
		while(n){
			ans+=n;
			n>>=1;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}