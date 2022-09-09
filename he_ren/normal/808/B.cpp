#include<cstdio>
#include<iostream>
typedef long long ll;
typedef long double db;
const int MAXN = 2e5 + 5;
using namespace std;

ll a[MAXN], s[MAXN];

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i) cin>>a[i];
	
	for(int i=1; i<=n; ++i) s[i]=s[i-1]+a[i];
	
	db ans=0;
	for(int i=1; i+k-1<=n; ++i)
	{
		ans+=(db)(s[i+k-1]-s[i-1])/(n-k+1);
	}
	
	printf("%.20lf",(double)ans);
	return 0;
}