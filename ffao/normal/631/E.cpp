#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
int a[210000];
ll sum[210000];

ll calc_move(int from, int to) {
	return a[from]*1ll*(to-from) - (sum[to]-sum[from]);
}

ll crossover(int from, int to) {
	ll headstart = calc_move(from,to);
	if (headstart < 0) return to;
	return to + 1 + headstart / (a[to]-a[from]);
}

ll solve() {
	ll ret = 0;
	deque<int> q;
	REP(i, n) sum[i] = (i == 0 ? 0 : sum[i-1]) + a[i];
	int largest_so_far = -100000000;
	REP(i, n) {
		if (a[i] > largest_so_far) {
			while (q.size() >= 2 && crossover(q[0], q[1]) >= crossover(q[0], i)) q.pop_back();
			q.push_back(i);
			largest_so_far = a[i];
		}
		while (q.size() >= 2 && crossover(q[0], q[1]) <= i) q.pop_front();
		ret = max(ret, calc_move(q[0], i));
	}
	return ret;
}

int main() {
	ll start_char = 0;
	scanf("%d", &n);
	REP(i,n) {
		scanf("%d", &a[i]);
		start_char += (i+1)*1ll*a[i];
	}

	ll best_delta = solve();
	reverse(a, a+n);
	REP(i, n) a[i] = -a[i];
	best_delta = max(best_delta, solve());

	printf("%lld\n", start_char + best_delta);
}