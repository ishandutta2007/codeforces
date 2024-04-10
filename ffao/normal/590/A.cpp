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

int a[610000];
int n;

int solve(int x, int y) {
	if (x == y) return 0;

	for (int i = x; i+1 <= y; i++) {
		if (a[i] == a[i+1]) return max(solve(x, i), solve(i+1, y));
	}

	int len = (y - x + 1);
	if (a[x] != a[y]) {
		int first = len/2;
		for (int i = x; i < x+first; i++) a[i] = a[x];
		for (int i = x+first; i <= y; i++) a[i] = a[y];
	}
	else {
		for (int i = x; i <= y; i++) a[i] = a[x];
	}

	return (len-1)/2;
}

int main() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	
	printf("%d\n", solve(0, n-1));
	REP(i, n) printf("%d ", a[i]);
}