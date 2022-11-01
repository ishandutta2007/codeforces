#include<iostream> 
using namespace std;
int main()
{
	
	int x;
	cin>>x;
	for(int n;x--;)
	{
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		int i;
		for(i=1;i<n&&a[i]-a[i-1]>-2&&a[i]-a[i-1]<2;i++);
		if(i==n)cout<<"NO\n";
		else cout<<"YES\n"<<i<<' '<<i+1<<endl;
	}
	return 0;
}