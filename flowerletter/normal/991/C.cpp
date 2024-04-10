#include <iostream>
#define int long long
using namespace std;
int n;
inline bool pd(int x)
{
	int a=0,y=0;
	int t=n;
	while(t)
	{
		a+=min(x,t);
		t-=min(t,x);
		y+=t/10;
		t-=t/10;
	}
	return a>=y;
}
signed main(int argc, char** argv) {
	cin >> n;
	int l=1,r=2e18,ans=0;
	while(l<=r)
	{
		int  mid=(l+r)/2;
		if(pd(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	 } 
	 cout << ans; 
	return 0;
}