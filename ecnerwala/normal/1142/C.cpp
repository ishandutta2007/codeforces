#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pt = pair<ll, ll>;
#define X first
#define Y second

// signed area of [a,b,c]
ll area(pt a, pt b, pt c) {
	return (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
}

const int MAXN = 1.1e5;
int N;
pt P[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i].X >> P[i].Y, P[i].Y -= P[i].X * P[i].X;
	sort(P, P + N);
	vector<pt> hull;
	for (int i = 0; i < N; i++) {
		pt nxt = P[i];
		while (!hull.empty() && hull.back().X == nxt.X) hull.pop_back();
		while (hull.size() >= 2) {
			pt cur = hull.back(); hull.pop_back();
			pt prv = hull.back();
			if (area(prv, cur, nxt) >= 0) {
				continue;
			} else {
				hull.push_back(cur);
				break;
			}
		}
		hull.push_back(nxt);
	}
	cout << int(hull.size()) - 1 << '\n';

	return 0;
}