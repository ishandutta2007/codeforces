#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 5;
vector<int> w[nax];
// leg is single/simple path ending with a leaf
bool del[nax]; // vertices in legs are marked as deleted
int legs[nax]; // numbers of legs starting in a vertex

void dfs(int a, int par = 0) {
	if(w[a].size() <= 2) {
		del[a] = true;
		for(int b : w[a]) if(b != par) dfs(b, a);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	for(int a = 1; a <= n; ++a)
		if(w[a].size() == 1)
			dfs(a);
	for(int a = 1; a <= n; ++a)
		for(int b : w[a]) if(del[b])
			legs[a] = min(legs[a]+1, 2); // at most two legs
	for(int a = 1; a <= n; ++a) if(!del[a]) {
		int cnt = 0;
		for(int b : w[a]) if(!del[b] && w[b].size() - legs[b] > 1)
			++cnt;
		if(cnt > 2) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}