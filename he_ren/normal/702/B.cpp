#include<cstdio>
#include<cmath>
#include<iostream>
#include<map>
typedef long long ll;
const int MAXN = 1e5 + 5;
const int lb=31;
using namespace std;

int a[MAXN];
map<ll,int> t;

int main(void)
{
	int n;
	scanf("%d",&n);
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
		for(int j=0; j<=lb; ++j)
			if(t.find((1ll<<j)-a[i]) != t.end())
				ans+=t[(1ll<<j)-a[i]];
		++t[a[i]];
	}
	
	cout<<ans;
	return 0;
}