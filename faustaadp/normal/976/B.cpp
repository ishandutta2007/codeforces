#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,k,h1,tem,h2;
char ct;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k<n)
	{
		cout<<k+1<<" "<<1<<"\n";
		return 0;
	}
	else
	{
		k-=n;
		h1=k/((m-1)*2);
		tem=k%((m-1)*2);
		if(tem<(m-1))
		{
			h1=n-h1*2;
			h2=tem+2;
		}
		else
		{
			h1=n-h1*2-1;
			tem-=(m-1);
			h2=m-tem;
		}
		cout<<h1<<" "<<h2<<"\n";
	}
}