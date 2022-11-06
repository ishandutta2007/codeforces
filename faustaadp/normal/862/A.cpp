#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;
ll n,x,i,a[101010],hs;
bool b[101010];
int main()
{
	cin>>n>>x;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=1;
	}
	if(b[x]==1)
		hs++;
	for(i=0;i<x;i++)
	{
		if(b[i]==0)
			hs++;
	}
	cout<<hs<<"\n";
}