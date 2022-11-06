#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],b[101010],poi,has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	poi=1;
	sort(b+1,b+1+n);
	for(i=1;i<=n;i++)
	{
		while(poi<=n&&b[poi]<=a[i])
			poi++;
		if(poi>n)
			break;
		has++;
		poi++;
	}
	cout<<has<<"\n";
}