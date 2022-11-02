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

const int maxN = 1000 + 5;
const int maxQ = 100000 + 233;
int n, m, q;
char s[maxN], t[maxN];
int ok[maxN], okk[maxN];
int pre[maxN], post[maxN];

int main() {
	memset(ok, 0, sizeof(ok));
	memset(okk, 0, sizeof(okk));
	cin >> n >> m >> q;
	cin >> s >> t;
	for(int i = 0; i + m - 1 < n; ++i) {
		for(int j = 0; j < m; ++j) if(t[j] != s[i + j]) goto FAIL;
		ok[i] = true; okk[i + m - 1] = true;
		FAIL: {}
	}
	pre[0] = ok[0]; post[0] = okk[0];
	for(int i = 1; i < n; ++i) pre[i] = pre[i - 1] + ok[i];
	for(int i = 1; i < n; ++i) post[i] = post[i - 1] + okk[i];
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r); --l; --r;
		int x = pre[l - 1], y = post[r];
		++x;
		printf("%d\n", max(y - x + 1, 0));
	}
	return 0;
}