#include <iostream>
using namespace std;

int a[10];

int main()
{
	int n,x,ans=0;
	cin >> n;
	while (n--) cin >> x, a[x]++;
	ans=a[4]+a[3]+a[2]/2;
	a[1]-=a[3];
	a[2]%=2;
	if (a[1]>0)
	{
		if (a[2]) ans++, a[1]-=2;
		if (a[1]>0) ans+=(a[1]+3)/4;
	}
	else ans+=a[2];
	cout << ans << endl;
}