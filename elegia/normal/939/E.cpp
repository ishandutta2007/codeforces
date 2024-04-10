#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;

int q;
int mx, cnt;
ll sum;
priority_queue<int> que;
priority_queue<int, vector<int>, greater<int> > que2;

int main() {
	int opt;
	scanf("%d%d%d", &q, &opt, &mx);
	sum = mx;
	cnt = 1;
	while (--q) {
		scanf("%d", &opt);
		if (opt == 2) {
			printf("%.9lf\n", mx - 1. * sum / cnt);
			continue;
		}
		int x;
		scanf("%d", &x);
		sum += x;
		++cnt;
		if (x > mx)
			swap(mx, x);
		que.push(x);
		while (!que.empty() && que.top() * (ll)cnt > sum) {
			sum -= que.top();
			--cnt;
			que2.push(que.top());
			que.pop();
		}
		while (!que2.empty() && que2.top() * (ll)cnt < sum) {
			sum += que2.top();
			++cnt;
			que.push(que2.top());
			que2.pop();
		}
		while (!que.empty() && que.top() * (ll)cnt > sum) {
			sum -= que.top();
			--cnt;
			que2.push(que.top());
			que.pop();
		}
		while (!que2.empty() && que2.top() * (ll)cnt < sum) {
			sum += que2.top();
			++cnt;
			que.push(que2.top());
			que2.pop();
		}
	}
	return 0;
}