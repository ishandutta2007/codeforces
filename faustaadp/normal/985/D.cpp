#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
ll n,H,L,R,C1,C2,CC1,CC2,mx=1000000000000000010,has,C;
ll kal(ll aa,ll bb)
{
	if(bb==0)
		return 0;
	if(bb==1)
		return aa;
	else
	{
		ll tem=kal(aa,bb/2);
		tem+=tem;
		tem=min(tem,mx);
		if(bb%2==1)
			tem+=aa;
		tem=min(tem,mx);
		return tem;
	}
}
ll com(ll aa,ll bb)
{
	
	if(aa>bb)
		return 0;
	ll A1=aa+bb,A2=bb-aa+1;
	if(A1%2==0)
		A1/=2;
	else
		A2/=2;
	return kal(A1,A2);
}
ll cek(ll aa)
{
	ll Le=aa+1,Ri=1e18,H=1e18,Ce;
	if(com(1,aa)>=n)
		return aa;
	if(com(1,aa)+aa>=n)
		return aa+1;
	while(Le<=Ri)
	{
		Ce=(Le+Ri)/2;
//		if(aa==10)
//			cout<<Le<<" "<<Ri<<" "<<com(aa,Ce-1)+com(1,Ce)<<"\n";
		if(com(aa,Ce-1)+com(1,Ce)>=n)
		{
//			if(aa==10)
//				cout<<Ce<<"\n";
			H=min(Ce+(Ce-aa),H);
			Ri=Ce-1;
		}
		else
			Le=Ce+1;
	}
	Le=aa,Ri=1e18;
	while(Le<=Ri)
	{
		Ce=(Le+Ri)/2;
//		if(aa==10)
//			cout<<Le<<" "<<Ri<<" "<<com(aa,Ce-1)+com(1,Ce)<<"\n";
		if(com(aa,Ce)+com(1,Ce)>=n)
		{
	//		if(aa==10)
	//			cout<<Ce<<"\n";
			H=min(Ce+(Ce-aa)+1,H);
			Ri=Ce-1;
		}
		else
			Le=Ce+1;
	}
	return H;
}
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	cout<<mx<<"\n";
	cin>>n>>H;
	L=1;
	R=H;
	has=min(cek(1),cek(H));
//	for(ll i=1;i<=H;i++)
//		cout<<i<<" "<<cek(i)<<"\n";
	while(L<=R)
	{
		C1=L+(R-L)/3;
		C2=R-(R-L)/3;
		CC1=cek(C1);
		CC2=cek(C2);
		if(CC1<CC2)
			R=C2-1;
		else
			L=C1+1;
		has=min(has,min(CC1,CC2));
	}
	L=1;
	R=H;
	while(L<=R)
	{
		C=(L+R)/2;
		if(cek(C)==C)
		{
			has=min(has,cek(C));
			R=C-1;
		}
		else
			L=C+1;
	}
//	cout<<C<<"\n";
	cout<<has<<"\n";
}