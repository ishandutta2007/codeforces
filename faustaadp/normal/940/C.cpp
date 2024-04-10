#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,z,b[101010],te,x[101010],i;
char a[101010],isi[101010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>z;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=1;
	}
	for(i='a';i<='z';i++)
		if(b[i])
		{
			te++;
			x[i]=te;
			isi[te]=char(i);
		}
	if(z>n)
	{
		for(i=n+1;i<=z;i++)
			a[i]=isi[1];
	}
	else
	{
		for(i=z;i>=1;i--)
			if(x[a[i]]==te)
			{
				a[i]=isi[1];
			}
			else
			{
				// cout<<isi[x[i]]<<"__\n";
				// cout<<isi[x[i]+1]<<"__\n";
				a[i]=isi[x[a[i]]+1];
				// cout<<i<<"_\n";	
				break;
			}
	}
	for(i=1;i<=z;i++)
		cout<<a[i];
	cout<<"\n";
}