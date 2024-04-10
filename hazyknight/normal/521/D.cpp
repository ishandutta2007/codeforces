#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

struct Frac
{
	ll a,b;
};

struct Opt
{
	int id,tp;
	
	Frac val;
	
	bool operator < (const Opt &p)const
	{
		if (val.a * p.val.b == p.val.a * val.b)
		{
			if (id == p.id)
				return tp < p.tp;
			return id < p.id;
		}
		return val.a * p.val.b < p.val.a * val.b;
	}
	
	bool operator == (const Opt &p)const
	{
		return tp == p.tp && id == p.id && val.a * p.val.b == val.b * p.val.a;
	}
};

struct Set
{
	priority_queue<Opt> Q,rQ;
	
	void insert(Opt a)
	{
		Q.push(a);
	}
	
	void erase(Opt a)
	{
		rQ.push(a);
	}
	
	Opt MAX()
	{
		while (!rQ.empty() && Q.top() == rQ.top())
		{
			Q.pop();
			rQ.pop();
		}
		return Q.top();
	}
}S;

int k,n,m;

ll a[MAXN];
ll A[MAXN];

pair<int,int> ass[MAXN];
vector<int> ans1,ans2,ans3;
vector<pair<int,int> > add[MAXN];
vector<pair<int,int> > mul[MAXN];

int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for (int i = 1;i <= k;i++)
	{
		scanf("%lld",&a[i]);
		A[i] = a[i];
	}
	for (int t,id,b,i = 1;i <= n;i++)
	{
		scanf("%d%d%d",&t,&id,&b);
		if (t == 1)
			ass[id] = max(ass[id],make_pair(b,i));
		if (t == 2)
			add[id].push_back(make_pair(b,i));
		if (t == 3)
			mul[id].push_back(make_pair(b,i));
	}
	for (int i = 1;i <= k;i++)
	{
		sort(add[i].begin(),add[i].end());
		sort(mul[i].begin(),mul[i].end());
		ass[i].first -= A[i];
		if (ass[i].first > 0)
			S.insert((Opt){i,1,(Frac){ass[i].first,a[i]}});
		if (add[i].size())
			S.insert((Opt){i,2,(Frac){add[i].back().first,a[i]}});
		if (mul[i].size())
			S.insert((Opt){i,3,(Frac){mul[i].back().first - 1,1}});
	}
	while (S.Q.size() > S.rQ.size() && m--)
	{
		Opt cur = S.MAX();
		int i = cur.id;
		if (ass[i].first > 0)
			S.erase((Opt){i,1,(Frac){ass[i].first,a[i]}});
		if (add[i].size())
			S.erase((Opt){i,2,(Frac){add[i].back().first,a[i]}});
		if (mul[i].size())
			S.erase((Opt){i,3,(Frac){mul[i].back().first - 1,1}});
		if (cur.tp == 1)
		{
			ans1.push_back(ass[i].second);
			a[i] += ass[i].first;
			ass[i] = make_pair(0,0);
		}
		if (cur.tp == 2)
		{
			ans2.push_back(add[i].back().second);
			a[i] += add[i].back().first;
			add[i].pop_back();
		}
		if (cur.tp == 3)
		{
			ans3.push_back(mul[i].back().second);
			mul[i].pop_back();
		}
		if (ass[i].first > 0)
			S.insert((Opt){i,1,(Frac){ass[i].first,a[i]}});
		if (add[i].size())
			S.insert((Opt){i,2,(Frac){add[i].back().first,a[i]}});
		if (mul[i].size())
			S.insert((Opt){i,3,(Frac){mul[i].back().first - 1,1}});
	}
	printf("%d\n",(int)(ans1.size() + ans2.size() + ans3.size()));
	for (int i = 0;i < ans1.size();i++)
		printf("%d ",ans1[i]);
	for (int i = 0;i < ans2.size();i++)
		printf("%d ",ans2[i]);
	for (int i = 0;i < ans3.size();i++)
		printf("%d ",ans3[i]);
	printf("\n");
	return 0;
}