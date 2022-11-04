#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> out[maxn] , in[maxn] , topol;

bool visited[maxn] , visited2[maxn] , kirekhar[maxn] , hide[maxn];

int n , m , color[maxn] , c = 1 , from[maxn] , to[maxn] , t[maxn];

void dfs(int v)
{
	visited[v] = 1;
	for(auto e : out[v])
		if(!hide[e] && !visited[to[e]])
			dfs(to[e]);
	topol.pb(v);
}

void sfd(int v)
{
	color[v] = c;
	for(auto e : in[v])
		if(!hide[e] && !color[from[e]])
			sfd(from[e]);
}

int cmp()
{
	memset(color , 0 , sizeof color);
	memset(visited , 0 , sizeof visited);
	c = 1;
	topol.clear();

	for(int i = 0; i < n; i++)
		if(!visited[i])
			dfs(i);
	reverse(topol.begin() , topol.end());
	for(auto v : topol)
		if(!color[v])
			sfd(v) , c++;
	return c - 1;
}

void kir(int v)
{
	visited2[v] = 1;
	for(auto e : out[v])
		if(kirekhar[to[e]] && !visited2[to[e]])
		{
			hide[e] = 1;
			if(cmp() == n)
			{
				cout << "YES" << endl;
				exit(0);
			}
			hide[e] = 0;
			kir(to[e]);
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a--;
		b--;
		from[i] = a;
		to[i] = b;
		out[a].pb(i);
		in[b].pb(i);
	}
	int x = cmp();
	if(x == n)
		return cout << "YES" << endl , 0;

	for(int i = 0; i < n; i++)
		t[color[i]]++;

	for(int i = 0; i < maxn; i++)
		if(t[i] > 1)
		{
			vector<int> shit;
			for(int j = 0; j < n; j++)
				if(color[j] == i)
					shit.pb(j) , kirekhar[j] = 1;
			kir(shit.back());
			memset(visited2 , 0 , sizeof visited2);
			for(int j = 0; j < n; j++)
				swap(in[j] , out[j]);
			for(int j = 0; j < m; j++)
				swap(from[j] , to[j]);
			kir(shit.back());
			cout << "NO" << endl;
			return 0;
		}
	
}