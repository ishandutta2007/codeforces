#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int MAXM = 2e5;

int N, M;

int par[MAXN];

int getpar(int a) {
	return (par[a] == a) ? a : (par[a] = getpar(par[a]));
}

void merge(int a, int b) {
	a = getpar(a), b = getpar(b);
	par[a] = b;
}

vector<int> adj[MAXN];

bool hasloop[MAXN];

int indeg[MAXN];

int main() {
	ios_base::sync_with_stdio(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		par[i] = i;
	}

	for(int i = 0; i < M; i++) {
		int s, t;
		cin >> s >> t;
		s--, t--;
		merge(s, t);
		adj[s].push_back(t);
		indeg[t] ++;
	}

	stack<int> st;

	for(int i = 0; i < N; i++) {
		if(!indeg[i]) st.push(i);
	}

	while(!st.empty()) {
		int v = st.top(); st.pop();
		for(int n : adj[v]) {
			assert(indeg[n]);
			indeg[n] --;
			if(!indeg[n]) st.push(n);
		}
	}

	for(int i = 0; i < N; i++) {
		if(indeg[i]) {
			hasloop[getpar(i)] = true;
		}
	}

	int res = N;

	for(int i = 0; i < N; i++) {
		if(par[i] == i && !hasloop[i]) res--;
	}

	cout << res << '\n';

	return 0;
}