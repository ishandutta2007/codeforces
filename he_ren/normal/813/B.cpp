#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
typedef long long ll;
const int LB = 60 + 5;
using namespace std;

ll px[LB],py[LB];
ll t[LB*LB],cnt=0;

int main(void)
{
	ll x,y,l,r;
	cin>>x>>y>>l>>r;
	
	int cx=log(r)/log(x), cy=log(r)/log(y);
	
	px[0]=py[0]=1;
	for(int i=1; i<=cx; ++i) px[i]=px[i-1]*x;
	for(int i=1; i<=cy; ++i) py[i]=py[i-1]*y;
	
	for(int i=0; i<=cx; ++i)
	{
		for(int j=0; j<=cy; ++j)
		{
			ll p=px[i]+py[j];
			if(p>=l && p<=r)
				t[++cnt] = p;
		}
	}
	
	sort(t+1,t+cnt+1);
	ll ans=0;
	t[0]=l-1; t[++cnt]=r+1;
	for(int i=1; i<=cnt; ++i)
		ans=max(ans,t[i]-t[i-1]-1);
	
	cout<<ans;
	return 0;
}