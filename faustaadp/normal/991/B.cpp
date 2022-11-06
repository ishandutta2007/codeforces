#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[10101],batas,sum;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	batas=9*n;
	batas=batas/2+batas%2;
	if(sum>=batas)
	{
		cout<<0<<"\n";
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		sum+=(5-a[i]);
		if(sum>=batas)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
}