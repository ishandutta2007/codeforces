#include <iostream>
#include <algorithm>
using namespace std;

int a[20200],n,ans,s[20200];

int main()
{
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i], ans+=a[i];
	
	for (int d=2;d<n;d++)
		if (n%d==0 && n/d>=3)
		{
			for (int i=0;i<n;i++)
				if (i<d) s[i]=a[i];
				else s[i%d]+=a[i];
			for (int i=0;i<d;i++) ans=max(ans,s[i]);
		}
		
	cout << ans << endl;
}