#include<iostream>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	string a[m],b[n];
	for(int i=0;i<m;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	int k;
	cin>>k;
	for(int j;k--;)
	{
		cin>>j;
		cout<<a[(j-1)%m]<<b[(j-1)%n]<<endl;
	}
	return 0;
}