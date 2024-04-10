//IOI2014
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
bool out[100005];
bool used[100005];
int main()
{
	srand((unsigned int)time(NULL));
	int n,m;
	cin >> n >> m;
	set<int>cur;
	set<int>ut;
	vector<pair<char,int> > query;
	
	for(int i=0;i<m;i++)
	{
		char c; int id;
		scanf(" %c%d",&c,&id);
		id--;
		query.pb(mp(c,id));
		if(!used[id])
		{
			used[id]=true;
			if(c=='-') cur.insert(id);
			else ut.insert(id);
		}
	}
	if(!cur.empty())
	{
		fill(out,out+n,true);
		for(set<int>::iterator it=cur.begin();it!=cur.end();it++)
		{
			out[*it]=false;
		}
		for(int i=0;i<n;i++)
		{
			if(!used[i]) out[i]=false;
		}
	}
	for(int i=0;i<m;i++)
	{
		char c=query[i].fi;
		int id=query[i].sc;
		if(c=='-')
		{
			set<int>::iterator it=cur.find(id);
			if(it != cur.end())
			{
				cur.erase(it);
			}
			if(!cur.empty()) out[id]=true;
			if(!out[id]) ut.insert(id);
		}
		else
		{
			set<int>::iterator it=ut.find(id);
			if(it != ut.end())
			{
				ut.erase(it);
			}
			
			for(set<int>::iterator it=ut.begin();it!=ut.end();it++)
			{
				out[*it]=true;
			}
			ut.clear();
			cur.insert(id);
		}
	}
	int res=count(out,out+n,false);
	cout << res << endl;
	if(!res) return 0;
	for(int i=0;i<n;i++) if(!out[i]) printf("%d ",i+1);
	puts("");
}