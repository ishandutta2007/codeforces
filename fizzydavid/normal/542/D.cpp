//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int hashsize=2097152;
//hash By YJZ
typedef unsigned long long ull;
struct Hash
{
	ll val[hashsize];
	ull key[hashsize];
	int size,mask;
	void clear(){memset(val,0,sizeof(ll));memset(key,0,sizeof(ull));}
	void init()
	{
		mask=hashsize-1;
		clear();
	}
	ll& operator[](ull id)
	{
		ull p=id*987&mask;
		for(;val[p]!=0&&key[p]!=id;p=(p+1)&mask);
		key[p]=id;
		return val[p];
	}
	ll find(ull id)
	{
		ull p=id*987&mask;
		for(;val[p]!=0&&key[p]!=id;p=(p+1)&mask);
		if(key[p]==id)return val[p];else return 0;
	}
};
Hash hs;
ll A;
vector<ll>fac;
vector<pair<ll,ll> >v;
ll dp[10000],add[10000];
void check(ll x)
{
	fac.PB(x);
	ll t=x;x--;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			while(x%i==0)x/=i;
			if(x!=1)return;
			v.PB(MP(i,t));
			return;
		}
	}
	if(x>1)v.PB(MP(x,t));
}
int main()
{
	hs.init();
	cin>>A;
	for(ll i=1;i*i<=A;i++)
	{
		if(A%i==0)
		{
			if(i*i==A)
				check(i);
			else
				check(i),check(A/i);
		}
	}
	sort(fac.begin(),fac.end());
	sort(v.begin(),v.end());
	for(int i=0;i<fac.size();i++)hs[fac[i]]=i+1;
	dp[0]=1;
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<fac.size();j++)
		{
			if(fac[j]*v[i].SS>A)break;
			ll t=fac[j]*v[i].SS;
			int pos=hs.find(t);
			if(pos!=0)
			{
				add[pos-1]+=dp[j];
			}
		}
		if(i+1==v.size()||v[i].FF!=v[i+1].FF)
		{
			for(int j=0;j<fac.size();j++)dp[j]+=add[j],add[j]=0;
		}
	}
	cout<<dp[int(fac.size())-1]<<endl;
	return 0;
}