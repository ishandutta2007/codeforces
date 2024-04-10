#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],ma,x[101010],has;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)ma=max(ma,a[i]);
	for(i=1;i<=n;i++)
		if(a[i]==ma)
		{
			if(i==1||a[i-1]!=ma)x[i]=1;
			else x[i]=x[i-1]+1;
			has=max(has,x[i]);
		}
	cout<<has<<"\n";
}