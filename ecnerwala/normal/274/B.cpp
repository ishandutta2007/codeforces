/*
ID: he.andr1
PROG: 274B
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int>::iterator itor;

const int MAXN = 100010;

int N;
ll V[MAXN];
vector<int> adj[MAXN];

pii dfs(int cur, int par) {
	if(adj[cur].size() == 1 && adj[cur][0] == par) return (V[cur] > 0) ? pii(V[cur], 0) : pii(0, -V[cur]);
	pii out(0, 0);
	for(itor i = adj[cur].begin(); i != adj[cur].end(); i++) {
		if(*i == par) continue;
		pii cnd = dfs(*i, cur);
		if(cnd.first > out.first) out.first = cnd.first;
		if(cnd.second > out.second) out.second = cnd.second;
	}
	V[cur] -= out.first;
	V[cur] += out.second;
	if(V[cur] > 0) out.first += V[cur];
	else out.second += -V[cur];
	return out;
}

void io() {
	cin >> N;
	for(int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < N; i++) {
		cin >> V[i];
	}
	pii out = dfs(0, -1);
	cout << out.first + out.second << '\n';
}

int main(){
	io();
	return 0;
}