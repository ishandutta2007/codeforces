//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
const ll B=10000;
ll tab[6];
ll F(int n,ll m)
{
	if(n==1)return m+min(m,B)-1;
	if(m<B)
	{
		ll cur=m;
		for(int i=1;i<=m;i++)
		{
			cur=F(n-1,cur)+1;
			cur++;
		}
		return F(n-1,cur);
	}
	else
	{
		return tab[n]+m;
	}
}
int query(vector<ll> &v)
{
	printf("%d",int(v.size()));
	for(int i=0;i<v.size();i++)printf(" %I64d",v[i]);
	puts("");
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	if(ret<0)exit(0);
	return ret;
}
void guess(int n,ll m)
{
	vector<ll> v;
	if(n==1)
	{
		for(int i=0;i<min(B,m);i++)v.PB(m+i);
	}
	else
	{
		ll cur=m;
		for(int i=1;i<=min(B,m);i++)
		{
			cur=F(n-1,cur)+1;
			v.PB(cur);
			cur++;
		}
	}
	int ret=query(v);
	if(ret==0)guess(n-1,m);
	else guess(n-1,v[ret-1]+1);
}
int main()
{
	tab[1]=B-1;
	for(int i=2;i<=5;i++)tab[i]=tab[i-1]*(B+1)+2*B;
	guess(5,1);
	return 0;
}