#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 1e5 + 200;

int N;
ll S[MAXN]; // start
ll C[MAXN]; // cap
ll D[MAXN]; // diff

const int MAXM = 1e5 + 200;
int M;

ll T[MAXM];
int L[MAXM];
int R[MAXM];

const int MAXQ = 1e6; // prolly enough
int Q;
pair<pii, pii> queries[MAXQ];
// A.A time
// A.B instruction number to insert into (-1 if inc->max transition)
// B.A left
// B.B right

ll incBit[MAXN]; //stores increment, if still incrementing
ll maxBit[MAXN]; //stores maxVal, if max reached

ll res[MAXM];

void insert(ll *bit, int a, ll v) {
	a++;
	for(int i = a; i <= N; i += i & (-i)) {
		bit[i] += v;
	}
}
ll query(ll *bit, int a) {
	a++;

	ll v = 0;
	for(int i = a; i > 0; i -= i & (-i)) {
		v += bit[i];
	}
	return v;
}

ll query(ll *bit, int l, int r) {
	return query(bit, r) - query(bit, l - 1);
}

map<pii, int> intervals; // when was each interval last updated?

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) cin >> S[i] >> C[i] >> D[i];
	cin >> M;
	for(int i = 0; i < M; i++) {
		cin >> T[i] >> L[i] >> R[i];
		L[i] --, R[i] --;
	}
	for(int i = 0; i < N; i++) {
		//initialize intervals to be length 1, set at -1
		intervals[pii(i, i)] = -1;
	}

	for(int i = 0; i < M; i++) {
		//generate intervals
		ll t = T[i];
		int l = L[i], r = R[i];
		while(true) {
			auto it = intervals.upper_bound(pii(r, N)); // find first one to right
			if(it == intervals.begin()) break;
			it--;
			auto v = *it;
			//if too far left
			if(v.A.B < l) break;
			if(v.A.B > r) {
				//split interval at r
				intervals[pii(v.A.A, r)] = v.B;
				intervals[pii(r + 1, v.A.B)] = v.B;
			} else if(v.A.A < l) {
				//split interval at l
				intervals[pii(v.A.A, l - 1)] = v.B;
				intervals[pii(l, v.A.B)] = v.B;
			} else if (v.B == -1) {
				res[i] += min(C[v.A.A], S[v.A.A] + t * D[v.A.A]);
			} else {
				queries[Q++] = make_pair(pii(t - v.B, i), v.A);
			}
			intervals.erase(it);
		}
		intervals[pii(l, r)] = t;
	}

	memset(incBit, 0, sizeof(incBit));
	memset(maxBit, 0, sizeof(maxBit));
	for(int i = 0; i < N; i++) {
		//initialize incBit
		insert(incBit, i, D[i]);

		//add transition events
		if(D[i] > 0) queries[Q++] = make_pair(pii(C[i] / D[i] + 1, -1), pii(i, i));
	}

	sort(queries, queries + Q);

	for(int i = 0; i < Q; i++) {
		ll time = queries[i].A.A;
		int type = queries[i].A.B;
		int l = queries[i].B.A;
		int r = queries[i].B.B;

		//cerr << time << ' ' << type << ' ' << l << ' ' << r << '\n';

		if(type == -1) {
			//assert(l == r);
			insert(incBit, l, -D[l]);
			insert(maxBit, l, C[l]);
		} else {
			//cerr << query(incBit, l, r) << ' ' << query(maxBit, l, r) << '\n';
			res[type] += time * query(incBit, l, r) + query(maxBit, l, r);
		}

	}

	for(int i = 0; i < M; i++) {
		cout << res[i] << '\n';
	}
	return 0;
}