#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll q,ta,an[2][6010101],TR[6010101],te;
char tc;
void masuk(ll aa,ll bb,ll ee,ll dd)
{
	TR[ee]+=dd;
	if(bb<0)return ;
	else
	{
		if(aa&(1<<bb))
		{
			if(an[1][ee]==0)an[1][ee]=++te;
			masuk(aa,bb-1,an[1][ee],dd);
		}
		else
		{
			if(an[0][ee]==0)an[0][ee]=++te;
			masuk(aa,bb-1,an[0][ee],dd);
		}
	}
}
ll cek(ll aa,ll bb,ll ee)
{
	if(bb<0)return 0;
	else
	{
		if(aa&(1<<bb))
		{
			if(!TR[an[0][ee]])return cek(aa,bb-1,an[1][ee]);
			else return (1<<bb)+cek(aa,bb-1,an[0][ee]);
		}
		else
		{
			if(!TR[an[1][ee]])return cek(aa,bb-1,an[0][ee]);
			else return (1<<bb)+cek(aa,bb-1,an[1][ee]);
		}
	}
}	
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>q;
	te=1;
	masuk(0,31,1,1);
	while(q--)
	{
		cin>>tc>>ta;
		if(tc=='+')masuk(ta,31,1,1);
		if(tc=='-')masuk(ta,31,1,-1);
		if(tc=='?')cout<<cek(ta,31,1)<<"\n";
	}
}