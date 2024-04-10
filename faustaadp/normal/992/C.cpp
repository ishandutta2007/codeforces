#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll mo=1000000007,x,k,o1,o2,o3,o4,o5,o6,o7,o8,o9,o10;
ll powo(ll aa,ll bb)
{
	if(bb==0)
		return 1;
	else
	{
		ll tem=powo(aa,bb/2);
		tem*=tem;
		tem%=mo;
		if(bb%2==1)
		{
			tem*=aa;
			tem%=mo;
		}
		return tem;
	}
}
ll kal(ll aa,ll bb)
{
	if(bb==0)
		return 0;
	else
	{
		ll tem=kal(aa,bb/2);
		tem+=tem;
		tem%=mo;
		if(bb%2==1)
		{
			tem+=aa;
			tem%=mo;
		}
		return tem;
	}
}
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>x>>k;
	if(x==0)
	{
		cout<<0<<"\n";
		return 0;
	}
	o2=powo(2,k)-1;
	o2%=mo;
	o3=x-1;
	o3%=mo;
	o4=kal(o2,o3);
	o4%=mo;
	o5=x%mo;
	o6=o5+o4;
	o6%=mo;
	o6*=2;
	o6%=mo;
	o7=powo(2,k)-1;
	o7%=mo;
	o8=o6+o7;
	o8%=mo;
	cout<<o8<<"\n";
}