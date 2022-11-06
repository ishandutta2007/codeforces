#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,a,b,i,j,ta,tb,hs;
int main()
{
	cin>>n>>a>>b;
	for(i=1;i<=200;i++)
	{
		for(j=1;j<=200;j++)
		{
			ta=a/i;
			tb=b/j;
			if(ta+tb>=n&&ta!=0&&tb!=0)
				hs=max(hs,min(i,j));
		}
	}
	cout<<hs<<"\n";
}