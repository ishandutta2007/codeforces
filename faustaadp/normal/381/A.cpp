#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[1010],h[2];
void hey(ll aa,ll bb,ll cc)
{
	if(aa>bb)
		return ;
	if(a[aa]>a[bb])
	{
		h[cc]+=a[aa];
		hey(aa+1,bb,1-cc);
	}
	else
	{
		h[cc]+=a[bb];
		hey(aa,bb-1,1-cc);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	hey(1,n,0);
	cout<<h[0]<<" "<<h[1]<<"\n";
}