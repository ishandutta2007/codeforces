#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,cl,ce,v,i,tg[101010],ek[101010],q,tem,has,X1,X2,Y1,Y2;
ll tcb(ll aa)
{
	ll L=1,R=cl,C,H=-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(tg[C]<=aa)
		{
			H=C;
			L=C+1;
		}
		else
			R=C-1;
	}
	return H;
}
ll tca(ll aa)
{
	ll L=1,R=cl,C,H=-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(tg[C]>=aa)
		{
			H=C;
			R=C-1;
		}
		else
			L=C+1;
	}
	return H;
}
ll ecb(ll aa)
{
	ll L=1,R=ce,C,H=-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(ek[C]<=aa)
		{
			H=C;
			L=C+1;
		}
		else
			R=C-1;
	}
	return H;
}
ll eca(ll aa)
{
	ll L=1,R=ce,C,H=-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(ek[C]>=aa)
		{
			H=C;
			R=C-1;
		}
		else
			L=C+1;
	}
	return H;
}
ll tang(ll aa)
{
	return abs(Y1-aa)+abs(aa-Y2)+abs(X1-X2);
}
ll eks(ll aa)
{
	return abs(Y1-aa)+abs(aa-Y2)+(ll)(abs(X1-X2)/v)+((abs(X1-X2)%v)!=0);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>cl>>ce>>v;
	for(i=1;i<=cl;i++)
		cin>>tg[i];
	for(i=1;i<=ce;i++)
		cin>>ek[i];
	sort(tg+1,tg+1+cl);
	sort(ek+1,ek+1+ce);
	cin>>q;
	while(q--)
	{
		cin>>X1>>Y1>>X2>>Y2;
		if(X1==X2)
		{
			cout<<abs(Y1-Y2)<<"\n";
			continue;
		}
		has=1e18;
		tem=tcb(Y1);
		if(tem!=-1)	has=min(has,tang(tg[tem]));
		tem=tca(Y1);
		if(tem!=-1)	has=min(has,tang(tg[tem]));
		tem=ecb(Y1);
		if(tem!=-1)	has=min(has,eks(ek[tem]));
		tem=eca(Y1);
		if(tem!=-1)	has=min(has,eks(ek[tem]));
		cout<<has<<"\n";		
	}
}