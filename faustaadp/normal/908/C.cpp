#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,j;
double r,ta,hz;
pair<double,double> a[1010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>r;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		hz=r;
		for(j=1;j<i;j++)
		{
			if(abs(a[j].fi-ta)<=2.0*r)
			{
			//	cout<<4.0*r*r<<" "<<a[j].fi*a[j].fi<<"\n";
				hz=max(hz,a[j].se+sqrt(4.0*r*r-((a[j].fi-ta)*(a[j].fi-ta))));
			}
		}
		a[i]=mp(ta,hz);
		if(i<n)
			cout<<fixed<<setprecision(10)<<hz<<" ";
		else
			cout<<fixed<<setprecision(10)<<hz<<"\n";
	}
}