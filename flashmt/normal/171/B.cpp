#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	long long ans=1;
	cin >> n;
	for (int i=1;i<n;i++) ans+=i*12;
	cout << ans << endl;
}