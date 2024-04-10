#pragma GCC optimize trapv
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

using pt = pair<ll, ll>;

const int MAXM = 7e5;
pt _pts[MAXM * 2];
pt *const pts = _pts + MAXM;
int headInd = 0, tailInd = 0;

pair<ll, ll> divMod(ll a, ll b) {
	assert(b > 0);
	ll d = a / b, m = a % b;
	if (m < 0) m += b, d--;
	return {d, m};
}

bool negCross(pt a, pt b) {
	// a.first * b.second <= a.second * b.first
	assert(a.first > 0 && b.first > 0);
	// b.second / b.first <= a.second / a.first
	ll adiv, arem; tie(adiv, arem) = divMod(a.second, a.first);
	ll bdiv, brem; tie(bdiv, brem) = divMod(b.second, b.first);
	if (adiv != bdiv) {
		return bdiv <= adiv;
	}
	return a.first * brem <= arem * b.first;
}

// returns whether cross(a, b, c) <= 0
// = cross(b-a, c-b)
bool negCross(pt a, pt b, pt c) {
	assert(a.first < b.first && b.first < c.first);
	return negCross(pt(b.first - a.first, b.second - a.second), pt(c.first - b.first, c.second - b.second));
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M;
	cin >> N >> M;

	if (N > 1) {
		headInd = 0, tailInd = 1;
		pts[headInd] = pt(0, 0);
		pts[tailInd] = pt(N-1, 0);
	} else {
		headInd = 0, tailInd = 0;
		pts[headInd] = pt(0, 0);
	}

	ll totB = 0;
	ll totS = 0;

	ll head = 0, tail = N-1;

	for (int q = 0; q < M; q++) {
		int t; cin >> t;
		if (t == 1) {
			ll k; cin >> k;
			{
				head --;
				k --;
				pt newPt(head, -(totB + totS * head));
				while (headInd + 1 <= tailInd && negCross(newPt, pts[headInd], pts[headInd + 1])) {
					headInd++;
				}
				pts[--headInd] = newPt;
			}
			if (k > 0) {
				head -= k;
				pt newPt(head, -(totB + totS * head));
				while (headInd + 1 <= tailInd && negCross(newPt, pts[headInd], pts[headInd + 1])) {
					headInd++;
				}
				pts[--headInd] = newPt;
			}
		} else if (t == 2) {
			ll k; cin >> k;
			{
				tail ++;
				k--;
				pt newPt(tail, -(totB + totS * tail));
				while (tailInd - 1 >= headInd && negCross(pts[tailInd - 1], pts[tailInd], newPt)) {
					tailInd--;
				}
				pts[++tailInd] = newPt;
			}
			if (k > 0) {
				tail += k;
				pt newPt(tail, -(totB + totS * tail));
				while (tailInd - 1 >= headInd && negCross(pts[tailInd - 1], pts[tailInd], newPt)) {
					tailInd--;
				}
				pts[++tailInd] = newPt;
			}
		} else if (t == 3) {
			ll b, s; cin >> b >> s;
			b += s * (0-head);
			totB += b;
			totS += s;
		} else assert(false);

		int mi = headInd - 1, ma = tailInd;
		while (ma - mi > 1) {
			int md = (mi + ma) >> 1;
			ll vlo = totB + totS * pts[md].first + pts[md].second;
			ll vhi = totB + totS * pts[md+1].first + pts[md+1].second;
			if (vlo <= vhi) {
				ma = md;
			} else {
				mi = md;
			}
		}
		cout << (pts[ma].first - head + 1) << ' ' << totB + totS * pts[ma].first + pts[ma].second << '\n';
	}

	return 0;
}