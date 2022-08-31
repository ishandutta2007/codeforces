#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const int MAXN = 1.5e5;
int N;
pii P[MAXN];

inline ll norm(const pii &p) {
	return ll(p.first) * ll(p.first) + ll(p.second) * ll(p.second);
}

pii add(const pii &p, const pii &q) {
	return pii(p.first + q.first, p.second + q.second);
}

pii sub(const pii &p, const pii &q) {
	return pii(p.first - q.first, p.second - q.second);
}

int A[MAXN];

int C[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}
	//assert(RAND_MAX >= N);
	for (int z = 0; true; z++) {
		srand(z);
		for (int i = 0; i < N; i++) {
			int j = (rand() << 15 ^ rand()) % (i+1);
			A[i] = A[j];
			A[j] = i;
		}

		pii cur(0, 0);
		for (int i = 0; i < N; i++) {
			pii a = P[A[i]];
			if (i + 1 < N) {
				pii b = P[A[i+1]];
				pii best = add(add(cur, b), a);
				C[A[i]] = 1, C[A[i+1]] = 1;
				{
					pii cnd = sub(add(cur, b), a);
					if (norm(cnd) < norm(best)) {
						best = cnd;
						C[A[i]] = -1, C[A[i+1]] = 1;
					}
				}
				{
					pii cnd = sub(sub(cur, b), a);
					if (norm(cnd) < norm(best)) {
						best = cnd;
						C[A[i]] = -1, C[A[i+1]] = -1;
					}
				}
				{
					pii cnd = add(sub(cur, b), a);
					if (norm(cnd) < norm(best)) {
						best = cnd;
						C[A[i]] = 1, C[A[i+1]] = -1;
					}
				}
				cur = best;
				i++;
			} else {
				pii best = add(cur, a);
				C[A[i]] = 1;
				pii cnd = sub(cur, a);
				if (norm(cnd) < norm(best)) {
					best = cnd;
					C[A[i]] = -1;
				}
				cur = best;
			}
		}

		if (norm(cur) <= ll(2.25e12)) {
			cerr << cur.first << ' ' << cur.second << '\n';
			break;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << C[i] << ' ';
	}
	cout << '\n';

	return 0;
}