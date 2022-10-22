#include <iostream>
using namespace std;
inline int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y;
}
int a[1005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int now=0;
		for(int i=1;i<=n;i++)
		{
			int mx=-1,pos=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]&&gcd(now,a[j])>=mx)
				{
					mx=gcd(now,a[j]),pos=j;
				}
			}
			cout << a[pos] << " ";
			now=gcd(now,a[pos]);
			a[pos]=0;
		}
		puts("");
	}
	return 0;
}