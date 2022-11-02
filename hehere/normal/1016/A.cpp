#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);


int main() {
	std::ios::sync_with_stdio(false);
	LL n, m;
	cin >> n >> m;
	LL k = 0;
	LL a;
	for(int i = 1; i <= n; ++i) {
		cin >> a;
		printf("%I64d ", (k + a) / m);
		k = (k + a) % m;
	}
	return 0;
}