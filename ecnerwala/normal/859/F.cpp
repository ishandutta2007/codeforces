#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5;
int N;
ll C;
ll S[MAXN];
ll P[MAXN];
ll B[MAXN]; // position to buy until (in shirt numbers)
ll T;

int main() {
	scanf("%d %lld", &N, &C);
	P[0] = 0;
	for (int i = 0; i < 2 * N - 1; i++) {
		int v; scanf("%d", &v);
		S[i] = v;
		P[i+1] = P[i] + S[i];
	}
	S[2*N-1] = 0;
	P[2*N] = P[2*N-1] + S[2*N-1];
	T = 0;
	priority_queue<pair<ll, int>> q; // offset, type
	q.emplace(0, -1);
	int cur_type = 0; // next type to buy
	while (!q.empty()) {
		ll offset = -q.top().first; int type = q.top().second; q.pop();
		ll pos = type == -1 ? 0 : B[type];
		//cerr << offset << ' ' << type << ' ' << T << ' ' << pos << '\n';
		if (offset != P[2 * type + 2] - pos) {
			continue;
		}
		if (T - pos >= C) {
			continue;
		}
		while (T < pos + C) {
			if (cur_type >= N) break;
			if (T + offset >= P[2 * cur_type + 1]) {
				cur_type ++;
				continue;
			}
			assert(cur_type > type);
			// buy up to P[2 * cur_type + 1] - offset of cur_type
			assert(P[2 * cur_type + 1] > T + offset);
			ll newT = min(pos + C, P[2 * cur_type + 1] - offset);
			assert(newT > T);
			T = B[cur_type] = newT;
			//cerr << cur_type << ' ' << T << '\n';
			q.emplace(-(P[2 * cur_type + 2] - B[cur_type]), cur_type);
		}
	}
	printf("%lld\n", T);
	return 0;
}