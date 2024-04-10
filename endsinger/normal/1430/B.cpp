#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k,a[N];
void sol()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	long long s=0;
	for(int i=1;i<=k+1;i++)
		s+=a[i];
	printf("%lld\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}