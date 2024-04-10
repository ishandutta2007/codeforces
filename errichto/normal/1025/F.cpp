#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
struct P {
	ll x, y;
	void read() {
		scanf("%lld%lld", &x, &y);
	}
	ll operator * (const P & he) const {
		return x * he.y - y * he.x;
	}
	bool operator < (const P & he) const {
		return *this * he < 0;
	}
	P operator - (const P & he) const {
		return P{x - he.x, y - he.y};
	}
	P operator - () const {
		return P{-x, -y};
	}
};
 
int main() {
	int n;
	scanf("%d", &n);
	vector<P> in(n);
	for(P & p : in) p.read();
	ll answer = 0;
	for(int i = 0; i < n; ++i) {
		vector<P> left, right;
		for(int j = 0; j < n; ++j) if(i != j) {
			P p = in[j] - in[i];
			if(make_pair(p.x, p.y) > make_pair(0LL, 0LL))
				right.push_back(p);
			else
				left.push_back(-p);
		}
		sort(left.begin(), left.end());
		sort(right.begin(), right.end());
		ll L = left.size(), R = right.size();
		int iL = 0;
		for(const P & p : right) {
			--R;
			while(iL < (int) left.size() && left[iL] < p) {
				++iL;
				--L;
				++R;
			}
			answer += (ll) L * (L - 1) / 2 * R * (R - 1) / 2;
			++L;
		}
	}
	printf("%lld\n", answer);
}