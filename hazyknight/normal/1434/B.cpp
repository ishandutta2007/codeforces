#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n,id;
int ans[MAXN];

vector<int> t[MAXN << 1];

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	int tot = 0;
	for (int i = 1;i <= 2 * n;i++)
	{
		char c;
		cin >> c;
		if (c == '+')
		{
			t[++id].push_back(++tot);
			Q.push(make_pair(0,id));
		}
		else
		{
			int v;
			cin >> v;
			if (Q.empty() || Q.top().first > v)
			{
				puts("NO");
				return 0;
			}
			id++;
			while (!Q.empty() && Q.top().first <= v)
			{
				int p = Q.top().second;
				if (t[p].size() > t[id].size())
					swap(t[p],t[id]);
				for (int j = 0;j < t[p].size();j++)
					t[id].push_back(t[p][j]);
				Q.pop();
			}
			ans[t[id].back()] = v;
			t[id].pop_back();
			if (t[id].size())
				Q.push(make_pair(v,id));
		}
	}
	puts("YES");
	for (int i = 1;i <= n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}