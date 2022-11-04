#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
const int maxn = 1e6 + 20;

string s;

vector<int> adj[maxn];

int f[maxn] , k;

set<int> st;
set<int>::iterator it;

bool ans[maxn];

void dfs(int v)
{
	st.insert(v);
	for(auto u : adj[v])
	{
		int l = 1 , r = u / k;
		while(r - l > 1)
		{
			int m = (r + l) / 2;
			if(u / m == k)
				r = m;
			else
				l = m;
		}
		l = r;
		r = u / k;
		it = st.lower_bound(u - r);
		if(r && u / r == k && it != st.end() && (*it) <= (u - l))
			ans[u] = 1;
		if(u % (k + 1) == 0 && st.find(u - u / (k + 1)) != st.end())
			ans[u] = 1;
		dfs(u);
	}
	st.erase(v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n >> k >> s;
	for(int i = 1; i < n; i++)
	{
		int k = f[i];
		while(k && s[k] != s[i])
			k = f[k];
		if(s[k] == s[i])
			k++;
		f[i + 1] = k;
	}
	
	for(int i = 1; i <= n; i++)
		adj[f[i]].pb(i);

	dfs(0);

	for(int i = 1; i <= n; i++)
		cout << ans[i];
	cout << endl;
}