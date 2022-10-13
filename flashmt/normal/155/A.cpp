#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,x,ans=0,m,M;
	cin >> n >> x;
	m=M=x;
	while (--n) 
	{
		cin >> x;
		if (x>M || x<m) ans++, m=min(m,x), M=max(M,x);
	}
	cout << ans << endl;
}