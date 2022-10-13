#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int h[2020],n,a,b;
	cin >> n >> a >> b;
	for (int i=0;i<n;i++) cin >> h[i];
	sort(h,h+n);
	cout << h[b]-h[b-1] << endl;
}