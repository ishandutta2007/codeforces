#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
int main(){
	scanf("%I64d",&n);
	if (n<5){
		printf("%d",n*(n-1)/2);
		return 0;
	}
	ll tmp=0,sum=0;
	for (;tmp<=n+n-1;tmp=tmp*10+9,sum++);
	tmp/=10; sum--;
	ll fuck=1;
	for (int i=1;i<=sum;i++)
		fuck*=10;
	for (;tmp<=n+n-1;tmp+=fuck)
		if (tmp<=n+1)
			ans+=tmp/2;
		else{
			ll r=tmp-n;
			ans+=(n-r+1)/2;
		}
	printf("%I64d",ans);
}