#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,a[555],b[555],price[555],x[555],y[555],z[555],ans=0;
	cin >> n;
	for (int i=0;i<n;i++) cin >> x[i] >> y[i] >> z[i];
	cin >> m;
	for (int i=0;i<m;i++) cin >> a[i] >> b[i] >> price[i];
	for (int i=0;i<n;i++)
	{
		int s=1000000000;
		x[i]=(x[i]+y[i])*2;
		for (int j=0;j<m;j++)
			if (a[j]>=z[i]) 
			{
				int t=a[j]/z[i];
				s=min(s,(x[i]+b[j]*t-1)/(b[j]*t)*price[j]);
			}
		ans+=s;
	}
	cout << ans << endl;
}