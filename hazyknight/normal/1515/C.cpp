#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

struct Set
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q,rQ;
	
	void insert(int p,int x)
	{
		Q.push(make_pair(x,p));
	}
	
	void erase(int p,int x)
	{
		rQ.push(make_pair(x,p));
	}
	
	pair<int,int> top()
	{
		while (!rQ.empty() && Q.top() == rQ.top())
		{
			Q.pop();
			rQ.pop();
		}
		return Q.top();
	}
	
	void clear()
	{
		while (!Q.empty())
			Q.pop();
		while (!rQ.empty())
			rQ.pop();
	}
}S;

int T,n,m,x;
int w[MAXN];
int s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&x);
		for (int i = 1;i <= n;i++)
			scanf("%d",&w[i]);
		S.clear();
		for (int i = 1;i <= m;i++)
		{
			s[i] = 0;
			S.insert(i,0);
		}
		puts("YES");
		for (int i = 1;i <= n;i++)
		{
			pair<int,int> tp = S.top();
			S.erase(tp.second,tp.first);
			printf("%d ",tp.second);
			s[tp.second] += w[i];
			S.insert(tp.second,s[tp.second]);
		}
		printf("\n");
	}
	return 0;
}