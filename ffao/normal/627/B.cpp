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

int tB[210000];
int tA[210000];
int orders[210000];

int n,k,a,b,q;

void upd(int *t, int x, int s) {
	while (x <= n+10) {
		t[x] += s;
		x += x&-x;
	}
}

int rd(int *t, int x) {
	int s = 0;
	while (x > 0) {
		s += t[x];
		x -= x&-x;
	}
	return s;
}

int main() {
	scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);

	for (int i = 0; i < q; i++) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int d, u;
			scanf("%d %d", &d, &u);
			if (orders[d] < b) {
				int diffB = min(b, orders[d]+u) - orders[d];
				//printf("diffB %d\n", diffB);
				upd(tB, d, diffB); 
			}

			int diffA = min(a, orders[d]+u) - orders[d];
			//printf("diffA %d\n", diffA);
			upd(tA, d, diffA);

			orders[d] = min(a, orders[d]+u);
		}
		else {
			int d;
			scanf("%d", &d);

			printf("%d\n", rd(tB, d-1) + rd(tA, n) - rd(tA, d+k-1));
		}
	}
}