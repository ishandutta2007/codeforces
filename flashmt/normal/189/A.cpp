#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,a,b,c,ans=0;
	cin >> n >> a >> b >> c;
	for (int i=0;i*a<=n;i++)
		for (int j=0;j*b+i*a<=n;j++)
			if ((n-i*a-j*b)%c==0)
				ans=max(ans,i+j+(n-i*a-j*b)/c);
	cout << ans << endl;
}