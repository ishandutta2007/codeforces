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
typedef complex<double> C;
LL mod=1e9+7;
LL cal(LL x){
	if(x==0)
	return 0;
	LL odd=0;
	LL even=0;
	LL Min = 0;
	while(true){
		Min++;
		if((1ll<<Min)>x){
			Min--;
			break;
		}
	}
	/*printf("%lld\n",x);
	printf("%lld\n",1ll<<Min);
	printf("%lld\n",1ll<<(Min+1));
	printf("%lld\n",Min);*/
	if(Min%2==1){
		for(LL i = 0;i<=Min;i+=2){
			odd+=(1ll<<i);
		}
		//odd = (1+Min)*((Min+1)/2)/2;
		even = x-odd;
	}
	else{
		for(LL i = 1;i<=Min;i+=2)
		even += 1ll<<i;//(2+Min)*(Min/2)/2;
		odd = x-even;
	}
	odd %=mod;
	even%=mod;
	//printf("%lld %lld %lld\n",x,odd,even);
	return (odd%mod*odd%mod+(1+even)%mod*even%mod)%mod;
}
int main()
{
	LL l,r;
	scanf("%lld %lld",&l,&r);
//	printf("%lld %lld\n",cal(r),cal(l-1));
	printf("%lld\n",((cal(r)-cal(l-1))%mod+mod)%mod);
}