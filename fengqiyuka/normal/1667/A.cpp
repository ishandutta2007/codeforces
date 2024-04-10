#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5010;
int a[N];

int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	ll Ans=5e18;
	for(int i=1;i<=n;i++){
		ll st=0;ll Sum=0;
		for(int j=i+1;j<=n;j++){
			ll t=st/a[j]+1;
			st=t*a[j];Sum+=t;
		}
		
		st=0;
		for(int j=i-1;j>=1;j--){
			ll t=st/a[j]+1;
			st=t*a[j];Sum+=t;
		}
		
		if(Ans>Sum) Ans=Sum;
	}
	
	printf("%lld\n",Ans);
	
	return 0;
}