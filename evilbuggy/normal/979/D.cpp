#include <bits/stdc++.h>
using namespace std;

const int K = 18;
const int N = 100005;
const int M = 40000005;

vector<int> fac[N];
int iter, tree[M][2], mini[M], chk[N], rt[N];

inline void insert(int root, int x){
	mini[root] = min(mini[root], x);
	for(int i = K - 1; i >= 0; i--){
		if((x >> i) & 1){
			if(tree[root][1] == -1){
				tree[root][1] = iter++;
			}
			root = tree[root][1];
			mini[root] = min(mini[root], x);
		}else{
			if(tree[root][0] == -1){
				tree[root][0] = iter++;
			}
			root = tree[root][0];
			mini[root] = min(mini[root], x);
		}
	}
}

inline int query(int root, int x, int s){
	if(s < mini[root])return -1;

	int ret = 0;
	for(int i = K - 1; i >= 0; i--){
		if((x >> i) & 1){
			if(tree[root][0] != -1){
				root = tree[root][0];
			}else{
				root = tree[root][1];
				ret ^= (1 << i);
			}
		}else{
			if(tree[root][1] != -1 && mini[tree[root][1]] <= s){
				root = tree[root][1];
				ret ^= (1 << i);
			}else{
				assert(tree[root][0] != -1);
				root = tree[root][0];
			}
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	iter = N;
	memset(chk, 0, sizeof(chk));
	memset(tree, -1, sizeof(tree));
	memset(mini, 0x7f, sizeof(mini));
	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j += i){
			fac[j].emplace_back(i);
		}
		rt[i] = i;
	}
	int q;
	cin >> q;
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int u;
			cin >> u;
			if(!chk[u]){
				chk[u] = 1;
				for(auto x : fac[u]){
					insert(rt[x], u);
				}
			}
		}else{
			int x, k, s;
			cin >> x >> k >> s;
			if(x%k != 0){
				cout << -1 << '\n';
				continue;
			}
			cout << query(rt[k], x, s - x) << '\n';
		}
	}

	return 0;
}