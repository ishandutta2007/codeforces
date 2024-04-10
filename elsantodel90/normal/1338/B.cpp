// http://codeforces.com/contest/1338/problem/B

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

bool parities[2];
int maxF;

const int MAXN = 1000000;

vector<int> g[MAXN];
int deg[MAXN];

void dfs(int node, int parent, int depth)
{
	if (deg[node] == 1)
		parities[depth%2] = true;
	int childrenLeaves = 0;
	for (int child : g[node])
	if (child != parent)
	{
		childrenLeaves += deg[child] == 1;
		dfs(child, node, depth+1);
	}
	maxF -= max(childrenLeaves - 1, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N; cin >> N;
	forn(i,N)
		deg[i] = 0;
	forn(i,N-1)
	{
		int a,b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	int root = -1;
	forn(i,N)
	if (deg[i] >= 2)
	{
		root = i;
		break;
	}
	assert(root >= 0);
	parities[0] = parities[1] = false;
	maxF = N-1;
	dfs(root, -1, 0);
	if (parities[0] && parities[1])
		cout << "3 ";
	else
		cout << "1 ";
	cout << maxF << "\n";
	return 0;
}