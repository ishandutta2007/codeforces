#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n; cin >> n;
	string a, b; cin >> a >> b;
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += min(abs(int(a[i]) - int(b[i])), 
					min(abs(int(a[i]) + 10 - int(b[i])),
					    abs(int(a[i]) - 10 - int(b[i]))));  
	cout << ans;
}