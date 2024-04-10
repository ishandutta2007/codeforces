#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;

int n;
bool ans[N];
char s[N];
string tmp;

string rvs(string str) {
	reverse(str.begin(), str.end());
	return str;
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%s", s + 1);
	n = strlen(s + 1);
	tmp = (s + 1);
	for (int i = 1; i < n; ++i) {
		string tt = tmp.substr(0, i);
		if (s[1 + i] + tt < tt + s[i + 1]) {
			ans[i] ^= 1;
			ans[i - 1] ^= 1;
			reverse(tmp.begin(), tmp.begin() + i);
			reverse(tmp.begin() + 1, tmp.begin() + i);
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}