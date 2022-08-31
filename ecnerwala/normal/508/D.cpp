#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
const int MAXV = 2 * MAXN;

int N;
int V;

vector<int> adj[MAXV];
int ind[MAXV];

int indeg[MAXV];
int outdeg[MAXV];

map<pair<char, char>, int> mp;
pair<char, char> strings[MAXV];

int getind(char a, char b) {
	pair<char, char> p(a, b);
	if(mp.count(p)) return mp[p];
	strings[V] = p;
	mp[p] = V;
	return V++;
}

int par[MAXV];
int getpar(int a) {
	return (par[a] == a) ? a : (par[a] = getpar(par[a]));
}
void merge(int a, int b) {
	a = getpar(a), b = getpar(b);
	par[b] = a;
}

stack<int> res;

void dfs(int a) {
	while(ind[a] < adj[a].size()) {
		dfs(adj[a][ind[a]++]);
	}
	res.push(a);
}

int main() {
	for(int i = 0; i < MAXV; i++) par[i] = i;
	cin >> N;
	for(int i = 0; i < N; i++) {
		string s; cin >> s;
		int l = getind(s[0], s[1]);
		int r = getind(s[1], s[2]);
		adj[l].push_back(r);
		outdeg[l]++;
		indeg[r] ++;
		merge(l, r);
	}

	for(int i = 0; i < V; i++) {
		if(getpar(i) != getpar(0)) {
			cout << "NO\n";
			return 0;
		}
	}

	int cnt = 0;
	for(int i = 0; i < V; i++) {
		cnt += abs(indeg[i] - outdeg[i]);
	}

	assert(cnt % 2 == 0);
	if(cnt > 2) {
		cout << "NO\n";
		return 0;
	}

	if(cnt == 2) {
		for(int i = 0; i < V; i++) {
			if(outdeg[i] > indeg[i]) {
				assert(outdeg[i] == indeg[i] + 1);
				dfs(i);
				break;
			}
		}
	} else {
		dfs(0);
	}

	cout << "YES\n";
	assert(res.size() == N + 1);
	cout << strings[res.top()].first;
	while(!res.empty()) {
		cout << strings[res.top()].second;
		res.pop();
	}
	cout << '\n';
	return 0;
}