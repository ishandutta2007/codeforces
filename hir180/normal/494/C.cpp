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
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
vector<P>und[5005];
int cnt[5005];
map<int,double>ma[5005];
int n,qq;
int a[100005];
P inv[5005];
double p[5005];
int k[5005];
bool used[5005];
int par[5005];
//map<P,vector<double> >ma;
bool cmp(pair<double,int> a,pair<double,int> b)
{
	return a.sc < b.sc;
}
map<int,double>merge(map<int,double>a,map<int,double>b)
{
	map<int,double>res;
	for(map<int,double>::iterator it = a.begin();it != a.end();it++)
	{
		for(map<int,double>::iterator it2 = b.begin();it2 != b.end();it2++)
		{
			if(it->sc * it2->sc > 0)
			{
				res[max(it->fi,it2->fi)] += it->sc * it2->sc;
			}
		}
	}
	return res;
}
void dfs(int v)
{
	int le = inv[v].fi;
	int nx = 0,maxv = -1;
	sort(und[v].begin(),und[v].end());
	while(le <= inv[v].sc)
	{
		if(nx!=und[v].size() && und[v][nx].fi == le)
		{
			dfs(und[v][nx].sc); le = inv[und[v][nx].sc].sc; nx++;
		}
		else
		{
			maxv = max(maxv,a[le]);
		}
		le++;
	}
	map<int,double>tmp;
	tmp[maxv] = 1.0; //cout << maxv << endl;
	for(int i=0;i<und[v].size();i++)
	{
		tmp = merge(tmp,ma[und[v][i].sc]);
	}
	for(map<int,double>::iterator it = tmp.begin();it != tmp.end();it++)
	{
		ma[v][it->fi] += it->sc * (1.0-p[v]);
		ma[v][it->fi+1] += it->sc * (p[v]);
	}
}
int main()
{
	scanf("%d%d",&n,&qq);
	memset(k,-1,sizeof(k));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<qq;i++)
	{
		scanf("%d%d%lf",&inv[i].fi,&inv[i].sc,&p[i]);
	}
	inv[qq] = mp(1,n); p[qq] = 0.0; qq++;
	int root = -1;
	for(int i=0;i<qq;i++)
	{
		par[i] = -1; int w = INF;
		for(int j=0;j<qq;j++)
		{
			if(i==j) continue;
			if(inv[i] == inv[j])
			{
				if(j<i)
				{
					par[i] = j; w = inv[i].sc-inv[i].fi;
				}
			}
			else if(inv[j].fi <= inv[i].fi && inv[i].sc <= inv[j].sc && inv[j].sc-inv[j].fi <= w)
			{
				par[i] = j; w = inv[j].sc-inv[j].fi;
			}
		}//cout << par[i] << " " << i << endl;
		if(par[i]!=-1) und[par[i]].push_back(mp(inv[i].fi,i));
		else root = i;
	}
	dfs(root);
	double res = 0.0;
	for(map<int,double>::iterator it = ma[root].begin();it != ma[root].end();it++)
	{
		res += (double) it->fi * it->sc;
	}
	printf("%f\n",res);
}