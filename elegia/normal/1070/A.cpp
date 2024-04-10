#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
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

const int D = 510, N = 5010; 

queue<pair<int, int> > q;
pair<int, pair<int, int> > lst[D][N];

void out(pair<int, int> pr) {
	if (lst[pr.first][pr.second].first == -2)
		return;
	out(lst[pr.first][pr.second].second);
	putchar(lst[pr.first][pr.second].first + '0');
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int d, s;
	scanf("%d%d", &d, &s);
	memset(lst, -1, sizeof(lst));
	lst[0][0].first = -2;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		if (tmp.first == 0 && tmp.second == s) {
			out(tmp);
			return 0;
		}
		for (int i = 0; i < 10; ++i) {
			pair<int, int> ne = make_pair((tmp.first * 10 + i) % d, tmp.second + i);
			if (ne.second <= s && lst[ne.first][ne.second].first == -1) {
				lst[ne.first][ne.second] = make_pair(i, tmp);
				q.push(ne);
			}
		}
	}
	puts("-1");

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}