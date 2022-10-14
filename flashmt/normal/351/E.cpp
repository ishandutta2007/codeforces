#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int a[2222], n;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
		
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int cntLeft = 0, cntRight = 0;
		for (int j = 0; j < i; j++) cntLeft += abs(a[j]) < abs(a[i]);
		for (int j = i + 1; j < n; j++) cntRight += abs(a[j]) < abs(a[i]);
		ans += min(cntLeft, cntRight);
	}
	
	cout << ans << endl;
}