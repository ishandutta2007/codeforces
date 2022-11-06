#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,j,a[101010],hs;
char ta;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=7;j++)
		{
			cin>>ta;
			if(ta=='1')
			{
				a[j]++;
				hs=max(hs,a[j]);
			}
		}
	}
	cout<<hs<<"\n";
}