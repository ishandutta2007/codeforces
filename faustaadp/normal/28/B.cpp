#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,P[110],p[110],ta;
ll car(ll aa)
{
	if(p[aa]==aa)return aa;
	else return p[aa]=car(p[aa]);
}
void gab(ll aa,ll bb)
{
	p[car(aa)]=p[car(bb)];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>P[i];
	for(i=1;i<=n;i++)p[i]=i;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(i-ta>=1)
			gab(i-ta,i);
		if(i+ta<=n)
			gab(i,i+ta);
	}
	for(i=1;i<=n;i++)
		if(car(i)!=car(P[i]))
		{
			cout<<"NO\n";
			return 0;
		}
	cout<<"YES\n";
}