#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,d[550][550];
char las,ct;
string s;	
ll depe(ll aa,ll bb)
{
	if(bb<aa)return 0;
	if(d[aa][bb]==-1)
	{
		d[aa][bb]=1+depe(aa+1,bb);
		ll ii;
		for(ii=aa+1;ii<=bb;ii++)
			if(s[ii]==s[aa])
				d[aa][bb]=min(d[aa][bb],depe(aa+1,ii-1)+depe(ii,bb));
	}
	return d[aa][bb];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	las='=';
	while(n--)
	{
		cin>>ct;
		if(ct!=las)s+=ct;
		las=ct;
	}
	n=s.length();
	memset(d,-1,sizeof(d));
	cout<<depe(0,n-1)<<"\n";
}