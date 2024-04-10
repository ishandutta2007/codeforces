//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
char ff[2005][2005];
int dist[2005][2005];
bool used[2005][2005]={};
vector<int>par,ran;
void init(int n){
	for(int i=0;i<n;i++){
		par.pb(i);
		ran.pb(0);
	}
}
int find(int x){
	if(par[x] == x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x == y) return ;
	if(ran[x]<ran[y]){
		par[x]=par[y];
	}else{
		par[y]=par[x];
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){
	return find(x)==find(y);
}

int main()
{
	int h,w;
	scanf("%d %d",&h,&w);
	for(int i=0;i<h;i++)
	{
		scanf("%s",&ff[i]);
	}
	queue<P1>que;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(ff[i][j]=='#')
			{
				que.push(mp(0,mp(i,j)));
				dist[i][j]=0;
			}
		}
	}
	vector<int>num;
	num.pb(0); num.pb(0);
	while(!que.empty())
	{
		P1 p=que.front(); que.pop();
		if(used[p.s.f][p.s.s]) continue;
		used[p.s.f][p.s.s]=true;
		if(num[0]<dist[p.s.f][p.s.s])
		{
			swap(num[0],num[1]);
			num[0]=dist[p.s.f][p.s.s];
		}
		else if(num[1]<dist[p.s.f][p.s.s])
		{
			num[1]=dist[p.s.f][p.s.s];
		}
		int dx[4]={0,1,0,-1};
		int dy[4]={-1,0,1,0};
		char g[4]={'>','^','<','v'};
		for(int i=0;i<4;i++)
		{
			if(0<=p.s.f+dx[i] && p.s.f+dx[i]<h)
			{
				if(0<=p.s.s+dy[i] && p.s.s+dy[i]<w)
				{
					if(ff[p.s.f+dx[i]][p.s.s+dy[i]]==g[i] && !used[p.s.f+dx[i]][p.s.s+dy[i]])
					{
						dist[p.s.f+dx[i]][p.s.s+dy[i]]=p.f+1;
						que.push(mp(dist[p.s.f+dx[i]][p.s.s+dy[i]],mp(p.s.f+dx[i],p.s.s+dy[i])));
					}
				}
			}
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(!used[i][j])
			{
				puts("-1");
				return 0;
			}
		}
	}
	vector<P1>gen;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(dist[i][j]==num[0] || dist[i][j]==num[1])
			{
				gen.pb(mp(dist[i][j],mp(i,j)));
			}
		}
	}
	init(gen.size());
	for(int t=0;t<num[0];t++)
	{
	map<P,vector<int> >ma; ma.clear();
	for(int i=0;i<gen.size();i++)
	{
		if(ff[gen[i].s.f][gen[i].s.s]=='^')
		{
			gen[i].s.f--;
			if(ff[gen[i].s.f][gen[i].s.s]!='#')
			{
				ma[gen[i].s].pb(i);
			}
		}
		else if(ff[gen[i].s.f][gen[i].s.s]=='v')
		{
			gen[i].s.f++;
			if(ff[gen[i].s.f][gen[i].s.s]!='#')
			{
				ma[gen[i].s].pb(i);
			}
		}
		else if(ff[gen[i].s.f][gen[i].s.s]=='<')
		{
			gen[i].s.s--;
			if(ff[gen[i].s.f][gen[i].s.s]!='#')
			{
				ma[gen[i].s].pb(i);
			}
		}
		else if(ff[gen[i].s.f][gen[i].s.s]=='>')
		{
			gen[i].s.s++;
			if(ff[gen[i].s.f][gen[i].s.s]!='#')
			{
				ma[gen[i].s].pb(i);
			}
		}
	}
	map<P,vector<int> >::iterator it;
	for(it=ma.begin();it!=ma.end();++it)
	{
		if(it->second.size()==1) continue;
		for(int i=1;i<(it->second).size();i++)
		{
			unite((it->second)[i-1],(it->second)[i]);
		}
	}

	}
	bool used[10000]={};
	int v1=-1,v2=-1;
	for(int i=0;i<gen.size();i++)
	{
		if(used[i]) continue;
		used[i]=true;
		int fa=-1;
		for(int j=i;j<gen.size();j++)
		{
			if(same(i,j))
			{
				fa=max(fa,gen[j].first);
				used[j]=true;
			}
		}
		if(v1<fa){ swap(v1,v2); v1=fa;}
		else if(v2<fa) v2=fa;
	}
	if(v2==-1) v2+=v1;
	printf("%d\n",max(0,v1+v2));
}