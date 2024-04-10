#include <bits/stdc++.h>
using namespace std;

int dfs(int x, int y, vector<int> ad[]) {
	int leaf = 1, sm = 0;
	for(auto it : ad[x]) {
		if(it != y) {
			int tmp = dfs(it, x, ad);
			if(tmp&1)
				leaf = 0;
			sm += (tmp>>1);
		}
	}
	if(x == 0)
		sm+=leaf;
	else
		sm += 2*leaf-1;
	return 2*sm+leaf;
}

int main() {
	int tc;
	cin>>tc;
	while(tc--) {
		int n;
		cin>>n;
		
		vector<int> ad[n];
		for(int i=0; i<n-1; i++) {
			int u, v;
			cin>>u>>v;
			ad[u-1].push_back(v-1);
			ad[v-1].push_back(u-1);
		}
		
		int tmp = dfs(0, -1, ad);
		cout<<(tmp>>1)<<'\n';
	}
	return 0;
}