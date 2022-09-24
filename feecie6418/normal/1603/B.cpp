#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
void Solve(){
	ll x,y,n;
	scanf("%lld%lld",&x,&y);
	if(x>y)printf("%lld\n",n=x+y);
	else if(x==y)printf("%lld\n",n=x);
	else printf("%lld\n",n=y-(y%x)/2);
	assert(n%x==y%n);
} 
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}