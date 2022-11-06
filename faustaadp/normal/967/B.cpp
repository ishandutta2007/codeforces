#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,A,B,i,a[101010],sum,p[101010],L,R,C,has;
bool cek(ll aa)
{
//	cout<<aa<<" "<<A*a[1]<<" "<<(sum-p[aa+1])*B<<"\n";
	return (A*a[1])>=((sum-p[aa+1])*B);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>A>>B;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	//sum-=a[1];
	sort(a+2,a+1+n);
	reverse(a+2,a+1+n);
	for(i=2;i<=n;i++)
		p[i]=p[i-1]+a[i];
	L=0;
	R=n-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(cek(C))
		{
			has=C;
			R=C-1;
		}
		else
			L=C+1;
	}
	cout<<has<<"\n";
}