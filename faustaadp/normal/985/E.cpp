#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,k,d,a[505050],x[505050],s[505050],i;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k>>d;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	x[n+1]=1;
	s[n+1]=1;
	for(i=n;i>=1;i--)
	{
		ll L=i+k-1,R=n,C,bts=-1;
		//cout<<i<<"---"<<L<<" "<<R<<"\n";
		while(L<=R)
		{
			C=(L+R)/2;
			if((a[C]-a[i])<=d)
			{
				bts=C;
				L=C+1;
			}
			else
				R=C-1;
		}
		if(bts!=-1)
		{
			L=i+k;
			R=bts+1;
			//if()
		//	cout<<i<<" "<<L<<" "<<R<<"\n";
			if((s[L]-s[R+1])>0)
				x[i]=1;
		}
		//cout<<i<<" "<<x[i]<<"\n";
		s[i]=s[i+1]+x[i];
	}
	if(x[1])cout<<"YES\n";
	else cout<<"NO\n";
}