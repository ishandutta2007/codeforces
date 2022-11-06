#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,a,b,has,i;
char c[202020];
ll d[202020][2];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b;
		for(i=1;i<=n;i++)
			cin>>c[i];
		has=b*n+b+a*n;
		d[0][0]=0;
		d[0][1]=1e18;
		for(i=1;i<=n;i++)
		{
			if(c[i]=='1')
			{
				d[i][0]=1e18;
				d[i][1]=min(d[i-1][1],d[i-1][0]+a)+b;
			}
			else
			{
				d[i][0]=min(d[i-1][0],d[i-1][1]+a+b);
				d[i][1]=min(d[i-1][0]+a,d[i-1][1])+b;
			}
		//	cout<<i<<" "<<d[i][0]<<" "<<d[i][1]<<"\n";
		}
		has+=d[n][0];
		cout<<has<<"\n";
	}
}