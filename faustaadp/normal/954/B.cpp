#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,hz;
char a[101010];
string sb(ll aa,ll bb)
{
	string z;
	ll ii;
	for(ii=aa;ii<=bb;ii++)
		z+=a[ii];
	return z;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	hz=-1;
	for(i=1;i<=n/2;i++)
	{
		if(sb(1,i)==sb(i+1,i+i))
		{
			hz=i;
		}
	}
	if(hz==-1)
		cout<<n<<"\n";
	else
		cout<<n-hz+1<<"\n";
}