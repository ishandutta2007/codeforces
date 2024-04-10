#include <iostream>
using namespace std;

int main()
{
	int n,k,a[55],ans=0;
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) ans+=(a[i]>0 && a[i]>=a[k]);
	cout << ans << endl;
}