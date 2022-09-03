#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
int mod=998244353;
int main(){
	LL n,k,a,b;
	scanf("%lld %lld %lld %lld",&n,&k,&a,&b);
	LL ans=0;
	while(n!=1){
		LL target = n/k*k;
		if(target==0)
		target=1;
		ans+=(n-target)*a;
		n=target;
		if(n==1)
		break;
		target = n/k;
		if((n-target)*a<=b){
			ans+=(n-1)*a;
			break;
		}
		n/=k;
		ans+=b;
	}
	printf("%lld\n",ans);
}