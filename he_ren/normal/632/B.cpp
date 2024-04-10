#include<cstdio>
#include<iostream>
typedef long long ll;
const int MAXN = 5e5 + 5;
using namespace std;

char s[MAXN];
ll p[MAXN];
ll a[MAXN],b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) cin>>p[i];
	scanf("%s",s+1);
	
	for(int i=1; i<=n; ++i)
	{
		a[i]=a[i-1];
		b[i]=b[i-1];
		if(s[i]=='A') a[i]+=p[i];
		else b[i]+=p[i];
	}
	
	ll ans=max(a[n],b[n]);
	for(int i=1; i<=n; ++i)
	{
		ans = max(ans, a[n]-a[i] + b[i]);
		ans = max(ans, b[n]-b[i] + a[i]);
	}
	cout<<ans;
	return 0;
}