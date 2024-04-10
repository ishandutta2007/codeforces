#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int w,h;
	long long ans=0;
	cin >> w >> h;
	for (int i=1;i<w;i++)
		for (int j=1;j<h;j++)
			ans+=min(i,w-i)*min(j,h-j);
	cout << ans << endl;
}