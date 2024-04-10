#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long ll;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		ll n;
		scanf("%lld",&n);
		
		ll t=1,e=n;
		while(e%2==0) t*=2,e/=2;
		t*=2;
		if(t<=e){
			ll t2=t*(t+1)/2;
			if(t2<=n) printf("%lld\n",t);
			else printf("-1\n");
		}
		else{
			if(e==1) printf("-1\n");
			else{
				ll t2=e*(e+1)/2;
				if(t2<=n) printf("%lld\n",e);
				else printf("-1\n");
			}
		}
	}
	
	return 0;
}