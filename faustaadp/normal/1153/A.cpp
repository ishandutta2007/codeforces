#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,t,ta,tb,has,ma=1e18,i;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>t;
	for(i=1;i<=n;i++)
	{
		cin>>ta>>tb;
		ll L=0,R=1000000,C,hz=0;
		while(L<=R)
		{
			C=(L+R)/2;
			ll tem=ta+C*tb;
			if(tem>=t)
			{
				hz=tem-t;
				R=C-1;
			}
			else
				L=C+1;
		}
		if(hz<ma)
		{
			ma=hz;
			has=i;
		}
	}
	cout<<has<<"\n";
}