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

#define INF 1000000000
const long long INFLL = 4500000000000000000LL;
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n, m, b;

struct guy {
	int money;
	int monitors;
	int problems;

	bool operator< (guy ot) const {
		return monitors < ot.monitors;
	}
};
guy g[200];

long long dist[1<<20];

int main() {
	scanf("%d %d %d", &n, &m, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &g[i].money);
		scanf("%d", &g[i].monitors);
		
		int j;
		for (scanf("%d", &j); j; j--) {
			int temp;
			scanf("%d", &temp); temp--;
			g[i].problems |= (1<<temp);
		}
	}

	for (int i = 0; i < (1<<m); i++) {
		dist[i] = INFLL;
	}
	dist[0] = 0;

	sort(g, g+n);
	long long ans = INFLL;

	for (int i = 0; i < n; i++) {
		for (int bm = 0; bm < (1<<m); bm++) {
			dist[bm] = min(dist[bm], dist[bm & (~g[i].problems)] + g[i].money);
		}

		ans = min(ans, dist[(1<<m)-1] + g[i].monitors * (long long)b);
	}

	if (ans == INFLL) printf("-1\n"); 
	else printf("%I64d\n", ans);
}