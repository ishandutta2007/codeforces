//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
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
map<int,vector<int> >ver,hor;
int n,m;
int val[2005][2005];
bool check(int t)
{
	vector<P1>V,H;
	map<int,vector<int> >::iterator it;
	for(it=ver.begin();it!=ver.end();++it)
	{
		int x=it->first;
		vector<int>vi=it->second;
		for(int j=0;j<vi.size();j++)
		{
			int le=vi[j]-2*t;
			int ri=vi[j]+2*t;
			if(!V.empty())
			{
				if(V[V.size()-1].f==x && V[V.size()-1].s.s>=le)
				{
					V[V.size()-1].s.s=ri;
				}
				else
				{
					V.pb(mp(x,mp(le,ri)));
				}
			}
			else
			{
				V.pb(mp(x,mp(le,ri)));
			}
		}
	}
	for(it=hor.begin();it!=hor.end();++it)
	{
		int x=it->first;
		vector<int>vi=it->second;
		for(int j=0;j<vi.size();j++)
		{
			int le=vi[j]-2*t;
			int ri=vi[j]+2*t;
			if(!H.empty())
			{
				if(H[H.size()-1].f==x && H[H.size()-1].s.s>=le)
				{
					H[H.size()-1].s.s=ri;
				}
				else
				{
					H.pb(mp(x,mp(le,ri)));
				}
			}
			else
			{
				H.pb(mp(x,mp(le,ri)));
			}
		}
	}
	memset(val,0,sizeof(val));
	for(int i=0;i<V.size();i++)
	{
		vector<int>zip;
		for(int j=0;j<H.size();j++)
		{
			if(V[i].f<H[j].s.f || H[j].s.s<V[i].f) continue;
			if(H[j].f<V[i].s.f || V[i].s.s<H[j].f) continue;
			for(int k=0;k<zip.size();k++)
			{
				if(val[zip[k]][j]++)
				{
					return 1;
				}
			}
			zip.pb(j);
		}
	}
	return 0;
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		ver[a+b].pb(a-b);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		hor[a-b].pb(a+b);
	}
	if(ver.size()<2 || hor.size()<2)
	{
		puts("Poor Sereja!");
		return 0;
	}
	map<int,vector<int> >::iterator it;
	for(it=ver.begin();it!=ver.end();++it)
	{
		sort(it->s.begin(),it->s.end());
	}
	for(it=hor.begin();it!=hor.end();++it)
	{
		sort(it->s.begin(),it->s.end());
	}
	int lb=0;
	int ub=1000005;
	//(lb,ub]
	while(ub-lb>1)
	{
		int mid=(ub+lb)/2;
		if(check(mid)) ub=mid;
		else lb=mid;
	}
	printf("%d\n",ub);
}