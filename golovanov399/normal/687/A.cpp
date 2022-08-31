#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

void panic(){
	puts("-1");
	exit(0);
}

int main(){

	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < m; i++){
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> color(n);
	for (int i = 0; i < n; i++){
		if (color[i] == 0){
			vector<int> st(1, i);
			color[i] = 1;
			while (!st.empty()){
				int v = st.back();
				st.pop_back();
				for (auto x : a[v]){
					if (color[x] == 0){
						color[x] = 3 - color[v];
						st.push_back(x);
					} else
					if (color[x] == color[v])
						panic();
				}
			}
		}
	}

	vector<int> qw[2];
	for (int i = 0; i < n; i++){
		qw[color[i] - 1].push_back(i);
	}

	for (int i = 0; i < 2; i++){
		printf("%d\n", (int)qw[i].size());
		for (auto x : qw[i]){
			printf("%d ", x + 1);
		}
		printf("\n");
	}

	return 0;
}