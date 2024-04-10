//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int cnt[40005],sum=0;
int val=-1;
bool ex[2005][2005]={};
pair<int,vector<int> > gen(ll val)
{
	vector<int>a6,a5,a4,a3,a2;
	int va[7]={};
	vector<vector<int> >ret;
	ll _val=val;
	for(int i=100;i>=1;i--)
	{
		ll x=1LL*i;
		x=x*x*x*x*x*x;
		if(x>val) continue;
		while(val>=x)
		{
			a6.pb(i);
			va[6]+=i*6;
			val-=x;
		}
	}
	val=_val;
	for(int i=100;i>=1;i--)
	{
		ll x=1LL*i;
		x=x*x*x*x*x;
		if(x>val) continue;
		while(val>=x)
		{
			a5.pb(i);
			va[5]+=i*5;
			val-=x;
		}
	}
	val=_val;
	for(int i=300;i>=1;i--)
	{
		ll x=1LL*i;
		x=x*x*x*x;
		if(x>val) continue;
		while(val>=x)
		{
			a4.pb(i);
			va[4]+=i*4;
			val-=x;
		}
	}
	val=_val;
	for(int i=1000;i>=1;i--)
	{
		ll x=1LL*i;
		x=x*x*x;
		if(x>val) continue;
		while(val>=x)
		{
			a3.pb(i);
			va[3]+=i*3;
			val-=x;
		}
	}
	val=_val;
	for(int i=40000;i>=1;i--)
	{
		ll x=1LL*i;
		x=x*x;
		if(x>val) continue;
		while(val>=x)
		{
			a2.pb(i);
			va[2]+=i*2;
			val-=x;
		}
	}
	int x=min((int)va[2],min((int)va[3],min((int)va[4],min((int)va[5],(int)va[6]))));
	if(va[2]==x) return mp(2,a2);
	if(va[3]==x) return mp(3,a3);
	if(va[4]==x) return mp(4,a4);
	if(va[5]==x) return mp(5,a5);
	if(va[6]==x) return mp(6,a6);
}
int main()
{
	srand((unsigned int)time(NULL));
	int k; scanf("%d",&k);
	int _k=k;
	for(int i=2;i*i<=k;i++)
	{
		if(_k%i==0)
		{
			while(_k%i==0)
			{
				cnt[i]++;
				_k/=i;
			}
		}
	}
	pair<int,vector<int> >vec3;
	int id=3;
	vector<P>vec2;
	if(_k>1) val=_k;
	else goto nxt;
	vec3=gen(val);
	for(int i=vec3.f;i<=vec3.f;i++)
	{
		vector<int>vi=vec3.s;
		for(int j=0;j<vi.size();j++)
		{
			int lb=1,ub=1;
			for(int d=0;d<i;d++)
			{
			for(int k=0;k<vi[j];k++)
			{
				for(int s=lb;s<=ub;s++)
				{
					ex[s][id+k]=ex[id+k][s]=true;
				}
			}
			lb=id; ub=id+vi[j]-1; id+=vi[j];
			}
			vec2.pb(mp(lb,ub));
		}
	}
	for(int i=0;i<vec2.size();i++)
	{
		for(int j=vec2[i].f;j<=vec2[i].s;j++)
		{
			ex[j][id]=ex[id][j]=true;
		}
	}
	 nxt:;
	if(id==3) ex[1][3]=ex[3][1]=true;
	for(int i=2;i*i<=k;i++)
	{
		if(cnt[i])
		{
			vec2.clear();
			int x=1;
			for(int j=1;j<=cnt[i];j++) x*=i; 
			vec3=gen(x); 
			int d=id++;
			for(int i=vec3.f;i<=vec3.f;i++)
			{
				vector<int>vi=vec3.s; 
				for(int j=0;j<vi.size();j++)
				{
					int lb=d,ub=d;
					for(int d=0;d<i;d++)
					{
					for(int k=0;k<vi[j];k++)
					{
						for(int s=lb;s<=ub;s++)
						{
							ex[s][id+k]=ex[id+k][s]=true;
						}
					}
					lb=id; ub=id+vi[j]-1; id+=vi[j];
					}
					vec2.pb(mp(lb,ub));
				}
			}
			for(int i=0;i<vec2.size();i++)
			{
				for(int j=vec2[i].f;j<=vec2[i].s;j++)
				{
					ex[j][id]=ex[id][j]=true;
				}
			}
			
		}
	}
	ex[id][2]=ex[2][id]=true;
	printf("%d\n",id);
	for(int i=1;i<=id;i++)
	{
		for(int j=1;j<=id;j++)
		{
			printf("%c",ex[i][j]?'Y':'N');
		}
		puts("");
	}
}