#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e5 + 100;

int a[3 * N], n, coord[N], szCoord;

int nextOff[4 * N * 3], tSize = 1, tMaxSize = 1, closestPos[4 * N];

int getMin(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) return 3 * n;
	if (l <= vl && vr <= r) return nextOff[v];
	return min(getMin(2 * v, vl, (vl + vr) / 2, l, r), getMin(2 * v + 1, (vl + vr) / 2, vr, l, r));
}

void setMin(int v, int val) {
//	cerr << v << " " << val << '\n';
	v += tSize;
	nextOff[v] = val;
	while(v) {
		v /= 2;
		nextOff[v] = min(nextOff[2 * v], nextOff[2 * v + 1]);
	}
}

int getOffPosition(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) return 3 * n;
	if (l <= vl && vr <= r) return closestPos[v];
	return min(getOffPosition(2 * v, vl, (vl + vr) / 2, l, r),
		getOffPosition(2 * v + 1, (vl + vr) / 2, vr, l, r));
}

void updateOff(int v, int val) {
	v += tMaxSize;
	closestPos[v] = val;
	while(v) {
		v /= 2;
		closestPos[v] = min(closestPos[2 * v], closestPos[2 * v + 1]);
	}
}

int gett(int x) {
	return lower_bound(coord, coord + szCoord, x) - coord;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    forn(i, n) {
		cin >> a[i];
		a[n + i] = a[2 * n + i] = a[i];
		coord[i] = a[i];
	}
	sort(coord, coord + n);
	szCoord = unique(coord, coord + n) - coord;

	forn(i, 4 * N) {
		closestPos[i] = 3 * n;
	}
	while(tMaxSize < n) tMaxSize *= 2;
	while(tSize < 3 * n) tSize *= 2;
	fornr(i, 3 * n) {
		int cur = gett(a[i]);
		int lastGood = gett((a[i] + 1) / 2);
		int val = getOffPosition(1, 0, tMaxSize, 0, lastGood);
//		cerr << i << " " << a[i] << " " << val << '\n';
		setMin(i, val);
		updateOff(cur, i);
	}
	
	forn(i, n) {
		int turnOffPosition = getMin(1, 0, tSize, i, i + n);
//		cout << turnOffPosition << '\n';
		if (turnOffPosition >= 3 * n) {
			cout << -1 << ' ';
		} else {
			cout << turnOffPosition - i << " ";
		}
	}
	cout << '\n';
    return 0;
}