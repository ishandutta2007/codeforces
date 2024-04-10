#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,d[2020][2020][2],mo=1e9+7;
ll depe(ll aa,ll bb,ll cc)
{
	if(aa==n)return 0;
	if(d[aa][bb][cc]!=-1)return d[aa][bb][cc];
	ll ret=0;
	if(bb==0)
	{
		if(cc==0)
		{
			ret=max(ret,depe(aa+1,bb+1,0));
			ret=max(ret,depe(aa+1,bb+1,1)+1);
		}
		else
		{
			ret=max(ret,depe(aa+1,bb+1,0));
		}
	}
	else
	if(bb==(n-aa))
	{	
		if(cc==0)
		{
			ret=max(ret,depe(aa+1,bb-1,0));
			ret=max(ret,depe(aa+1,bb-1,1)+1);
		}
		else
		{
			ret=max(ret,depe(aa+1,bb-1,0));
		}
	}
	else
	{
		if(cc==0)
		{
			ret=max(ret,depe(aa+1,bb+1,0)+depe(aa+1,bb-1,0));
			ret=max(ret,depe(aa+1,bb+1,0)+depe(aa+1,bb-1,1)+1);
			ret=max(ret,depe(aa+1,bb+1,1)+depe(aa+1,bb-1,0));
			//ret=max(ret,depe(aa+1,bb+1,1)+depe(aa+1,bb-1,1)+2);
		}
		else
		{
			ret=max(ret,depe(aa+1,bb+1,0)+depe(aa+1,bb-1,0));
		}
	}
//	cout<<aa<<" "<<bb<<" "<<cc<<" "<<ret<<"\n";
	ret%=mo;
	return d[aa][bb][cc]=ret;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	memset(d,-1,sizeof(d));
	n*=2;
	cout<<depe(0,0,0)<<"\n";
}