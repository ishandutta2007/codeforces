#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 150005;

struct State
{
	long long v;
	vector<int> pos;
	bool operator < (const State &p)const
	{
		return v > p.v;
	}
};

int n,id;
long long a[MAXN];
long long rematch[MAXN];
int tot;
pair<int,long long> ans[MAXN];

map<int,int> match;
vector<int> s[MAXN];
priority_queue<State> Q;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (!match[a[i]])
			rematch[match[a[i]] = ++id] = a[i];
		a[i] = match[a[i]];
	}
	for (int i = 1;i <= n;i++)
		s[a[i]].push_back(i);
	for (int i = 1;i <= id;i++)
		Q.push((State){rematch[i],s[i]});
	while (!Q.empty())
	{
		long long v = Q.top().v;
		vector<int> cur = Q.top().pos;
		Q.pop();
		while (!Q.empty() && Q.top().v == v)
		{
			for (int i = 0;i < Q.top().pos.size();i++)
				cur.push_back(Q.top().pos[i]);
			Q.pop();
		}
		sort(cur.begin(),cur.end());
		if (cur.size() & 1)
		{
			ans[++tot] = make_pair(cur.back(),v);
			cur.pop_back();
		}
		if (!cur.size())
			continue;
		vector<int> t;
		for (int i = 1;i < cur.size();i += 2)
			t.push_back(cur[i]);
		Q.push((State){v * 2,t});
	}
	sort(ans + 1,ans + tot + 1);
	cout << tot << endl;
	for (int i = 1;i <= tot;i++)
		cout << ans[i].second << ' ';
	cout << endl;
	return 0;
}