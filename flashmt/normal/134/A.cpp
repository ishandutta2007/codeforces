#include <iostream>
using namespace std;

int n,s,a[200200],ans[200200],r;

int main()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i], s+=a[i];
	for (int i=1;i<=n;i++)
		if (a[i]*n==s) ans[r++]=i;
	cout << r << endl;
	for (int i=0;i<r;i++) cout << ans[i] << ' ';
}