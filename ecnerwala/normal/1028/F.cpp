#include<bits/stdc++.h>
using namespace std;

using ll = long long;

using pii = pair<int, int>;

ll sq(int i) {
	return ll(i) * ll(i);
}

ll norm(pii p) {
	return sq(p.first) + sq(p.second);
}

pii ang(pii a, pii b) {
	pii r(a.first + b.first, a.second + b.second);
	int g = __gcd(r.first, r.second);
	r.first /= g;
	r.second /= g;
	return r;
}

map<ll, set<pii>> circles;
map<pii, int> numsave;

int main() {
	ios_base::sync_with_stdio(0);
	int Q;
	cin >> Q;
	int nPts = 0;
	for (int z = 0; z < Q; z++) {
		int t; pii p; cin >> t >> p.first >> p.second;
		if (t == 1) {
			// add pt
			set<pii>& circle = circles[norm(p)];

			assert(!circle.count(p));

			for (pii q : circle) {
				// numsave[ang(p, q)] ++;
				// numsave[ang(q, p)] ++;
				numsave[ang(p, q)] += 2;
			}

			circle.insert(p);
			numsave[ang(p, p)] ++;

			nPts ++;
		} else if (t == 2) {
			// remove pt
			set<pii>& circle = circles[norm(p)];

			assert(circle.count(p));

			nPts --;

			numsave[ang(p, p)] --;
			circle.erase(p);

			for (pii q : circle) {
				// numsave[ang(p, q)] --;
				// numsave[ang(q, p)] --;
				numsave[ang(p, q)] -= 2;
			}
		} else if (t == 3) {
			p = ang(p, p);
			cout << nPts - numsave[p] << '\n';
		}
	}

	return 0;
}