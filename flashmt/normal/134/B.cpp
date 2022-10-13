#include <iostream>
#include <algorithm>
using namespace std;

int calc(int x,int y)
{
	if (y==1) return x-1;
	if (x%y==0) return 1000000;
	int t=x/y;
	return calc(y,x-y*t)+t;
}

int main()
{
	int n,ans;
	cin >> n;
	ans=n-1;
	for (int i=2;i*2<=n;i++) ans=min(ans,calc(n,i));
	cout << ans << endl;
}