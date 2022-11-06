#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,i,has,j;
ll powo(ll aa,ll bb,ll cc)
{
	if(bb==0)
		return 1;
	else
	{
		ll tem=powo(aa,bb/2,cc);
		tem=(tem*tem)%cc;
		if(bb%2==1)
			tem=(tem*aa)%cc;
		return tem;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<n;i++)
	{
		ll gagal=0;
		for(j=1;j<(n-1);j++)
			if(powo(i,j,n)==1){
				gagal=1;
				break;
			}
		if(powo(i,n-1,n)!=1)
			gagal=1;
		if(!gagal)has++;
	}
	cout<<has<<"\n";
}