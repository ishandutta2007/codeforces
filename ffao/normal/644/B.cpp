#include <bits/stdc++.h> 

using namespace std;

typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n,b;
long long ans[210000];
queue< pair<int, int> > q;

void solve() {
	scanf("%d %d", &n, &b);

	long long q_free = 0;
	REP(i,n) {
		int t, d;
		scanf("%d %d", &t, &d);
		while (!q.empty() && q_free <= t) {
			pii task = q.front();
			q.pop();
			q_free = ans[task.second] = q_free + task.first;
		}

		if (q_free <= t) {
			q_free = ans[i] = t + d;
		}
		else if ((int)q.size() < b) {
			q.push({d, i});
		}
		else ans[i] = -1;
	}
	while (!q.empty()) {
		pii task = q.front();
		q.pop();
		q_free = ans[task.second] = q_free + task.first;
	}

	REP(i,n) printf("%lld ", ans[i]);
	printf("\n");
}

int main() {
    solve();
}