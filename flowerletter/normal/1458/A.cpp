#include <iostream>
#define int long long
using namespace std;
int a[200005],b[200005];
inline int gcd(int x,int y)
{
	if(y<0) y=-y;
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y; 
}
signed main(int argc, char** argv) {
	int n,m,G=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=2;i<=n;i++)
		G=gcd(G,a[i]-a[i-1]);
	for(int i=1;i<=m;i++)
		cin >> b[i];
	for(int i=1;i<=m;i++)
	{
		cout << gcd(G,b[i]+a[1]) << " ";
	}
	return 0;
}