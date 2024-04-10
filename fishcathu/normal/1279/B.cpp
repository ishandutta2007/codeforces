#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int n,m;x--;)
	{
		cin>>n>>m;
		int ans,s=0;
		for(int i=1,max=0,j;i<=n;i++)
		{
			cin>>j;
			if(s<=m)
			{
				if(j>max)max=j,ans=i;
				s+=j;
			}
		}
		if(s<=m)cout<<"0\n";
		else cout<<ans<<endl;
	}
	return 0;
}