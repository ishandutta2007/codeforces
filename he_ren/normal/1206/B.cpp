#include<cstdio>
#include<iostream>
typedef long long ll;
const int MAXN = 1e5 + 5;
using namespace std;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	ll ans=0;
	int cnt=0,cnt0=0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]<0) ans+=(ll)-a[i]-1, ++cnt;
		if(a[i]==0) ++cnt0;
		if(a[i]>0) ans+=(ll)a[i]-1;
	}
	
	if(cnt&1)
		if(!cnt0) ans+=2;
	
	ans += cnt0;
	cout<<ans;
	return 0;
}