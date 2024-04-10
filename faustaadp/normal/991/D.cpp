#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],b[101010],d[1010][1010];
string s1,s2;
ll depe(ll aa,ll bb)
{
	if(aa==n||bb==n)
		return 0;
	if(aa>n||bb>n)
		return -1e18;
	if(d[aa][bb]==-1)
	{
		if(aa==bb)
		{
			d[aa][bb]=max(depe(aa+1,bb),depe(aa,bb+1));
			if(a[aa]==1&&b[bb]==1&&a[aa+1]==1)
				d[aa][bb]=max(d[aa][bb],1+depe(aa+2,bb+1));
			if(a[aa]==1&&b[bb]==1&&b[bb+1]==1)
				d[aa][bb]=max(d[aa][bb],1+depe(aa+1,bb+2));
		}
		else
		if(aa<bb)
		{
			d[aa][bb]=depe(aa+1,bb);
			if(a[aa]==1&&b[bb]==1&&a[aa+1]==1)
				d[aa][bb]=max(d[aa][bb],1+depe(aa+2,bb+1));
		}
		else
		{
			d[aa][bb]=depe(aa,bb+1);
			if(a[aa]==1&&b[bb]==1&&b[bb+1]==1)
				d[aa][bb]=max(d[aa][bb],1+depe(aa+1,bb+2));
		}
	//	cout<<aa<<" "<<bb<<" "<<d[aa][bb]<<"\n";
	}
	return d[aa][bb];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s1>>s2;
	n=s1.length();
	for(i=0;i<n;i++)
	{
		if(s1[i]=='0')
			a[i]=1;
		if(s2[i]=='0')
			b[i]=1;
	}
	memset(d,-1,sizeof(d));
	cout<<depe(0,0)<<"\n";
}