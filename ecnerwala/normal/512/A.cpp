#include<bits/stdc++.h>
using namespace std;

int D = 26;
vector<int> adj[50];
int indeg[50];

string go() {
	int N; cin >> N;
	string prv; cin >> prv;
	for(int i = 1; i < N; i++) {
		string cur; cin >> cur;
		assert(prv != cur);

		if(prv.size() > cur.size() && prv.substr(0, cur.size()) == cur) return "Impossible";

		for(int i = 0; i < prv.size() && i < cur.size(); i++) {
			if(prv[i] == cur[i]) continue;
			int p = prv[i] - 'a';
			int c = cur[i] - 'a';
			adj[p].push_back(c);
			indeg[c]++;
			break;
		}

		prv = cur;
	}
	stack<int> q;
	for(int i = 0; i < D; i++) {
		if(indeg[i]) continue;
		q.push(i);
	}
	string res;
	while(!q.empty()) {
		int v = q.top(); q.pop();
		res.push_back(char(v + 'a'));
		for(int n : adj[v]) {
			indeg[n] --;
			if(!indeg[n]) {
				q.push(n);
			}
		}
	}
	if(res.size() == D) return res;
	return "Impossible";
}

int main() {
	ios_base::sync_with_stdio(0);
	cout << go() << '\n';
	return 0;
}