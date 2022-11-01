#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int n;x--;)
	{
		cin>>n;
		string a;
		cin>>a;
		int i,ans=1;
		for(i=0;i<n&&a[i]=='P';i++);
		for(int j=0;i<=n;i++,j++)
		{
			if(a[i]!='P')
			{
				if(j>ans)ans=j;
				j=0;
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
}