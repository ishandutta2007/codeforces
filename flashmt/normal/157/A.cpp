#include <iostream>
using namespace std;

int main()
{
	int n,a[33][33],ans=0;
	cin >> n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) 
			cin >> a[i][j];
	
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			int dif=0;
			for (int k=0;k<n;k++) dif+=a[i][k]-a[k][j];
			ans+=dif<0;
		}
		
	cout << ans << endl;
}