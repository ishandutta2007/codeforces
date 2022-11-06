#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 300000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
ll n,x;
int main(){
	scanf("%lld",&n);
	rep(i,2,n){
		if(1ll*i*i>n)break;
		if(!(n%i)){x=i;break;}
	}
	if(!x)x=n;
	printf("%I64d\n",(n-x)/2+1);
}