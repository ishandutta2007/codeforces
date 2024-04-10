#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int k,n,a[101][101]={0};
	vector <int> extra;
	
	cin >> k;
	for (n=3;;n++)
		if (n*(n+1)*(n-1)/6>k)
		{
			k-=n*(n-1)*(n-2)/6;
			break;
		}
		
	for (int i=n;k;i--)
		while (k>=i*(i-1)/2)
		{
			k-=i*(i-1)/2;
			extra.push_back(i);
		}
		
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			a[i][j]=i!=j;
	
	for (int i=0;i<extra.size();n++,i++)
		for (int j=0;j<extra[i];j++)
			a[n][j]=a[j][n]=1;
			
	cout << n << endl;
	for (int i=0;i<n;i++,cout << endl)
		for (int j=0;j<n;j++)
			cout << a[i][j];
}