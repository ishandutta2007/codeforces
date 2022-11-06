#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,a,b,i,d[202020],te,tem,has;
char ct;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b;
	te=1;
	for(i=1;i<=n;i++)
	{
		cin>>ct;
		if(d[te]!=0&&ct=='*')
			te++;
		else
		if(ct=='.')
			d[te]++;
	}
	for(i=1;i<=te;i++)
	{
	//	cout<<d[i]<<"\n";
		if(a<b)
			swap(a,b);
		tem=min(d[i]/2+d[i]%2,a);
		a-=tem;
		has+=tem;
		tem=min(d[i]/2,b);
		b-=tem;
		has+=tem;
	}
	cout<<has<<"\n";
}