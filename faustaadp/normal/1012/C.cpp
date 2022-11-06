#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,k,i,a[5050],d[5050][2555][2];
ll depe(ll aa,ll bb,ll cc)
{
	if(d[aa][bb][cc]==-1)
	{
		if(aa>n&&bb==0){d[aa][bb][cc]=0;return d[aa][bb][cc];}
		if(aa>n){d[aa][bb][cc]=1e18;return d[aa][bb][cc];}
		ll ki=a[aa-1];
		if(cc==1)ki=min(ki,a[aa-2]-1);
		d[aa][bb][cc]=depe(aa+1,bb,0);
		d[aa][bb][cc]=min(d[aa][bb][cc],depe(aa+2,bb-1,1)+max(0LL,ki-a[aa]+1)+max(0LL,a[aa+1]-a[aa]+1));
	}
	return d[aa][bb][cc];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	k=n/2+n%2;
	a[0]=-1e18;
	a[n+1]=-1e18;
	for(i=1;i<=n;i++)cin>>a[i];
	memset(d,-1,sizeof(d));
	for(i=1;i<=k;i++)
		cout<<depe(1,i,0)<<" ";
	cout<<"\n";
}