#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int laz;

struct Set
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q,rQ;
	
	void insert(pair<int,int> a)
	{
		a.first -= laz;
		Q.push(a);
	}
	
	void erase(pair<int,int> a)
	{
		a.first -= laz;
		rQ.push(a);
	}
	
	int MIN()
	{
		while (!rQ.empty() && Q.top() == rQ.top())
		{
			Q.pop();
			rQ.pop();
		}
		return Q.empty() ? 1e9 : Q.top().first + laz;
	}
}s[MAXN],S;

int n;
int a[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	S.insert(make_pair(1,0));
	s[a[0]].insert(make_pair(1,0));
	for (int i = 2;i <= n;i++)
	{
		int t = S.MIN() + 1,tt = s[a[i]].MIN();
		laz += (a[i] != a[i - 1]);
		S.insert(make_pair(min(t,tt),i - 1));
		s[a[i - 1]].insert(make_pair(min(t,tt),i - 1));
	}
	printf("%d\n",S.MIN());
	return 0;
}