#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[22]={1000},z;
	cin >> a[1] >> a[2] >> z;
	//int ans=max(a[1],a[2]);
	int ans=max(a[1],a[2]);
	for (int i=3;i<=z+1;i++) a[i]=a[i-1]+a[i-2];
	
	for (int i=2;i<=z;i++) ans+=min(a[i],a[i-1]);
				
	cout << ans << endl;
}