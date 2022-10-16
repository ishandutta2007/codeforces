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

int p[501];
int oc[501];
int a[501][501];
int n;

int main() {
	scanf("%d", &n);

	REP(i, n) REP(j,n) scanf("%d", &a[i][j]);

	for (int s = 1; s <= n; s++) {
		for (int i = 0; i < n; i++) if (!oc[i]) {
			bool ok = true;
			for (int j = 0; j < n; j++) if (!oc[j] && j != i) {
				if (a[i][j] != s) {
					ok = false;
					break;
				}
			}
			if (ok) {
				p[i] = s;
				oc[i] = 1; 
				break;
			}
		}
	}

	REP(i,n) printf("%d ", p[i]);
}