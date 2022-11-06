#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll i,tem,j,q,l,r,h;
vector<ll> v,du;
unordered_map<ll,bool> me;
ll binser(ll aa,ll bb)
{
	ll L,R,C,H1=v.size(),H2=-1;
	L=0;
	R=v.size()-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(v[C]>=aa)
		{
			H1=C;
			R=C-1;
		}
		else
			L=C+1;
	}
	L=0;
	R=v.size()-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(v[C]<=bb)
		{
			H2=C;
			L=C+1;
		}
		else
			R=C-1;
	}
	//cout<<H1<<" "<<H2<<"\n";
	//cout<<v[H1]<<" "<<v[H2]<<"\n";
	return H2-H1+1;
}
ll tam(ll aa,ll bb)
{
	ll Le,Re;
	Re=sqrt(bb);
	Le=sqrt(aa);
	if(Le*Le<aa)
		Le++;
	ll L,R,C,H1=du.size(),H2=-1,H;
	L=0;
	R=du.size()-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(du[C]>=Le)
		{
			H1=C;
			R=C-1;
		}
		else
			L=C+1;
	}
	L=0;
	R=du.size()-1;
	while(L<=R)
	{
		C=(L+R)/2;
		if(du[C]<=Re)
		{
			H2=C;
			L=C+1;
		}
		else
			R=C-1;
	}
	return (Re-Le+1)-(H2-H1+1);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	v.pb(1);
	du.pb(1);
	me[1]=1;
	for(i=2;i<=1000000;i++)
	{
		tem=i*i;
		while(1)
		{
//			if(tem*i<0||tem*i>1000000000000000000)
			if((double)4000000000000000000/(double)tem<(double)i)
				break;
			if(me[tem*i]==0&&tem*i<=1000000000000000000)
			{
				me[tem*i]=1;
				v.pb(tem*i);
				du.pb(tem*i);
			}
			tem*=i;
		}
	}
	//cout<<v.size()<<"\n";
	for(i=1;i<=100000;i++)
		if(me[i*i]==0)
			du.pb(i*i);
	sort(v.begin(),v.end());
	sort(du.begin(),du.end());
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		h=binser(l,r);
		h+=tam(l,r);
		cout<<h<<"\n";
	}
}