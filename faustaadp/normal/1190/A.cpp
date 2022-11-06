#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,k,i,a[101010],kan,te,has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
		cin>>a[i];
	kan=0;
	te=1;
	while(te<=m)
	{
		ll sisa=(a[te]-kan);
		if(sisa>0)
		{
			ll zz=(sisa/k)+((sisa%k)!=0);
			kan+=zz*k;
		}
		has++;
		ll tom=0;
		while(te<=m&&a[te]<=kan)
		{
			tom++;
			te++;
		}
		kan+=tom;
	}
	cout<<has<<"\n";
}