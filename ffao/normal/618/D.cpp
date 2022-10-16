#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
const int mod = 1000000007;

vector<int> adj[1100000];
int inc[1100000];
int lc[1100000];
int mark[1100000];
int x,y;

queue<int> leaves;

int main() {
	scanf("%d %d %d", &n, &x, &y);

	for (int i = 0; i < n-1; i++) {
		int u,v;
		scanf("%d %d", &u, &v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		inc[u]++; inc[v]++;
	}

	if (y < x) {
		REP(i,n) if (inc[i] == n-1) {
			printf("%lld\n", y * 1ll * (n-2) + x);
			return 0;
		}

		printf("%lld\n", y * 1ll * (n-1));
		return 0;
	}

	REP(i,n) if (inc[i] == 1) {
		leaves.push(i);
	}

	int pairs = 0;
	int lk = 0;

	while (!leaves.empty()) {
		int v = leaves.front();
		leaves.pop();
		mark[v] = 1;

		if (lc[v] == 0) {
			lc[v] = 1;
		}
		
		if (lc[v] > 1) {
			pairs += lc[v] - 1;
			lc[v] = 0;
		}

		lk = v;

		for (int c : adj[v]) if (!mark[c]) {
			inc[c]--;
			if (inc[c] == 1) leaves.push(c);
			lc[c] += lc[v];
		}
	}

	pairs += lc[lk];
	printf("%lld\n", (pairs-1) * 1ll * y + (n-pairs) * 1ll * x);
}