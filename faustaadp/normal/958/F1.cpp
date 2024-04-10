#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,a[1010],b[1010],he,tem[1010],ha,j;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
	{
		cin>>b[i];
		he+=b[i];
	}
	for(i=1;i+he-1<=n;i++)
	{
		for(j=1;j<=m;j++)
			tem[j]=b[j];
		ha=0;
		for(j=i;j<=i+he-1;j++)
		{
			tem[a[j]]--;
		}
		for(j=1;j<=m;j++)
			if(tem[j]==0)
				ha++;
		if(ha==m)
		{
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
}