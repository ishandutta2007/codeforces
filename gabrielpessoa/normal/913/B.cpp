#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int SIZE  = 1005;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

vi g[SIZE];

int contaLeaf(int p) {
	int num = 0;
	for(int a : g[p]) {
		if(g[a].empty()) num++;
	}
	return num;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		int p;
		scanf("%d", &p);
		g[p].push_back(i);
	}
	for(int i = 1; i <= n; i++) {
		if(!g[i].empty() && contaLeaf(i) < 3) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}