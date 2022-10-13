#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,a[100100];
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	
	int ans=0;
	for (int i=0,j=0;i<n;i++)
	{
		while (j<n && a[j]<=a[i]*2) j++;
		ans=max(ans,j-i);
	}
	
	cout << n-ans << endl;
}