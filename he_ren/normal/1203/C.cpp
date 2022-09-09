#include<cstdio>
#include<cmath>
#include<iostream>
typedef long long ll;
const int MAXN = 4e5 + 5;
using namespace std;

inline ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}

ll a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) cin>>a[i];
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
		ans = gcd(a[i],ans);
	
	ll sq = sqrt(ans), res=0;
	for(ll i=1; i<=sq; ++i)
	{
		if(ans%i == 0)
			res+=2;
	}
	if(sq*sq==ans) --res;
	cout<<res;
	return 0;
}