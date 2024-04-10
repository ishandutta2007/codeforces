#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,a[101010],kanan,kiri,has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	n++;
	a[n]=m;
	for(i=1;i<=n;i+=2)
		has+=a[i]-a[i-1];
	for(i=2;i<=n;i+=2)
		kanan+=a[i]-a[i-1];
	for(i=1;i<=n;i+=2)
	{
		if(a[i]-1!=a[i-1])
		has=max(has,kiri+kanan+(a[i]-1-a[i-1]));
	//	cout<<kiri<<" "<<kanan<<" "<<a[i]-1-a[i-1]<<"\n";
		kanan-=a[i+1]-a[i];
		kiri+=a[i]-a[i-1];
	}
	kiri=a[1];
	kanan=0;
	for(i=4;i<=n;i+=2)
		kanan+=a[i]-a[i-1];
	for(i=1;i<n;i+=2)
	{
		if(a[i+1]-1!=a[i])
		has=max(has,kiri+kanan+a[i+1]-1-a[i]);
//		cout<<kiri<<" "<<kanan<<" "<<a[i+1]-1-a[i]<<"\n";
		kanan-=a[i+3]-a[i+2];
		kiri+=a[i+2]-a[i+1];
	}
	cout<<has<<"\n";
}