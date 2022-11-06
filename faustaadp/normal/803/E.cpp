#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,d[1010][2020],i;
char a[1010];	
ll depe(ll aa,ll bb)
{
	if((aa==(n+1))&&(abs(1000-bb)==k))return 1;
	if(abs(1000-bb)==k)return 0;
	if(aa==(n+1))return 0;
	if(d[aa][bb]==-1)
	{
		d[aa][bb]=0;
		if(a[aa]=='?')
		{
			if(depe(aa+1,bb+1))
			{
				d[aa][bb]=1;
			}
			if(depe(aa+1,bb))
			{
				d[aa][bb]=1;
			}
			if(depe(aa+1,bb-1))
			{
				d[aa][bb]=1;
			}
		}
		else
		{
			if(a[aa]=='W')d[aa][bb]=depe(aa+1,bb+1);
			if(a[aa]=='D')d[aa][bb]=depe(aa+1,bb);
			if(a[aa]=='L')d[aa][bb]=depe(aa+1,bb-1);
		}
	//	cout<<aa<<" "<<bb<<" "<<d[aa][bb]<<"\n";
	}
	return d[aa][bb];
}
void jalan(ll aa,ll bb)
{
	if(aa==(n+1))cout<<"\n";
	else
	{
		if(a[aa]=='?')
		{
			if(depe(aa+1,bb+1))
			{
				cout<<"W";
				jalan(aa+1,bb+1);
			}
			else if(depe(aa+1,bb))
			{
				cout<<"D";
				jalan(aa+1,bb);
			}
			else if(depe(aa+1,bb-1))
			{
				cout<<"L";
				jalan(aa+1,bb-1);
			}
		}
		else
		{
			if(a[aa]=='W')cout<<"W";
			if(a[aa]=='D')cout<<"D";
			if(a[aa]=='L')cout<<"L";
			if(a[aa]=='W')jalan(aa+1,bb+1);
			if(a[aa]=='D')jalan(aa+1,bb);
			if(a[aa]=='L')jalan(aa+1,bb-1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	memset(d,-1,sizeof(d));
	if(depe(1,1000))
	{
		jalan(1,1000);
	}
	else
		cout<<"NO\n";
}