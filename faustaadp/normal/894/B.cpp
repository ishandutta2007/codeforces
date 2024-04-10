#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll ta,tb,tc,mo=1000000007,mi;
ll powo(ll aa,ll bb)
{
	if(bb==0)
		return 1;
	else
	if(bb==1)
		return aa;
	ll tj=powo(aa,bb/2);
	tj*=tj%mo;
	if(bb%2==1)
		tj*=aa%mo;
	tj%=mo;
	return tj;
}
ll pewe(ll aa,ll bb)
{
	if(bb==0)
		return 1;
	else
	if(bb==1)
		return aa;
	ll tj=powo(aa,bb/2);
	tj*=tj%mi;
	if(bb%2==1)
		tj*=aa%mi;
	tj%=mi;
	return tj;
}
int main()
{
	mi=mo-1;
	cin>>ta>>tb>>tc;
	if((ta+tb)%2==1&&tc==-1)
	{
		cout<<0<<"\n";
		return 0;
	}/*
	if(ta==1||tb==1)
	{
		if(tc==1)
			cout<<1<<"\n";
		if(tc==-1)
		{
			if((ta+tb)%2==0)
				cout<<1<<"\n";
			else
				cout<<0<<"\n";
		}
		return 0;
	}*/
//	if(ta+tb>1010101010101010101)
		cout<<powo(2,mi+((ta-1)%mi)*((tb-1)%mi)%mi)<<"\n";
//	else
//		cout<<powo(2,(ta-1)*(tb-1))<<"\n";
}