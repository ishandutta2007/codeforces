#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,k,i,p[101010],ang[101010],mo=1e9+7,has,ta,tb,tc,taa,tbb;
ll car(ll aa)
{
	if(p[aa]==aa)return aa;
	else return p[aa]=car(p[aa]);
}
ll powo(ll aa,ll bb)
{
	if(bb==0)return 1;
	else
	{
		ll tem=powo(aa,bb/2);
		tem=(tem*tem)%mo;
		if(bb%2==1)tem=(tem*aa)%mo;
		return tem;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(i=1;i<=n;i++)p[i]=i;
	for(i=1;i<=n;i++)ang[i]=1;
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb>>tc;
		if(tc==0)
		{
			taa=car(ta);
			tbb=car(tb);
			if(taa!=tbb)
			{
				p[taa]=tbb;
				ang[tbb]+=ang[taa];
			}
		}
	}
	has=powo(n,k);
	for(i=1;i<=n;i++)
		if(car(i)==i)
		{
		//	cout<<i<<" "<<ang[i]<<"\n";
			has=(has-powo(ang[i],k)+mo)%mo;
		}
	cout<<has<<"\n";	
}