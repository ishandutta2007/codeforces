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

const int N = 5e5 + 100;
const int INF = 1e9 + 7;

vector<int> q[N];
int leftPos[4 * N], tSize, segLen[N], a[N];
ll tree[4 * N], psh[4 * N];

void drop(int len) {
	q[len].pop_back();
	int curPos = tSize + len - 1;
	if (sz(q[len])) {
		leftPos[curPos] = q[len].back();
	} else {
		leftPos[curPos] = INF;
	}
	while(curPos) {
		curPos /= 2;
		leftPos[curPos] = min(leftPos[2 * curPos], leftPos[2 * curPos + 1]);
	}
}

int getLeftest(int v, int vl, int vr, int len) {
	if (vl + 1 == vr) {
		return leftPos[v];
	}
	int vm = (vl + vr) / 2;
	if (vm <= len) {
		return getLeftest(2 * v + 1, vm, vr, len);
	}
	int leftRes = getLeftest(2 * v, vl, vm, len);
	return min(leftRes, leftPos[2 * v + 1]);
}

void push(int v, int vl, int vr) {
	if (!psh[v]) {
		return;
	}
	int len = (vr - vl) / 2;
	forn(i, 2) {
		psh[2 * v + i] += psh[v];
		tree[2 * v + i] -= len * psh[v];
	}
	psh[v] = 0;
}

void subseg(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) {
		return;
	}
	if (l <= vl && vr <= r) {
		tree[v] -= vr - vl;
		psh[v]++;
		return;
	}
	push(v, vl, vr);
	subseg(2 * v, vl, (vl + vr) / 2, l, r);
	subseg(2 * v + 1, (vl + vr) / 2, vr, l, r);
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	forn(i, n) {
		a[i] = s[i] - '0';
	}
	vector<pii> segs;
	int wait = 1;
	forn(i, n) {
		if (a[i] == 1) {
			if (wait) {
				segs.pb(mp(i, 1));
				wait = 0;
			} else {
				segs.back().snd++;
			}
		} else {
			wait = 1;
		}
	}
	fornr(i, sz(segs)) {
		q[segs[i].snd].pb(segs[i].fst);
		segLen[segs[i].fst] = segs[i].snd;
	}
	tSize = 1;
	while(tSize < n) tSize *= 2;
	forn(i, tSize * 2) leftPos[i] = INF;
	forn(i, n) {
		if (sz(q[i + 1])) {
			leftPos[tSize + i] = q[i + 1].back();
		}
	} 
	fornr(i, tSize) {
		leftPos[i] = min(leftPos[2 * i], leftPos[2 * i + 1]);
	}
	int p = 0;
	int best = 0;
	forn(i, n) {
		int cur = 0;
		if (p < sz(segs)) {
			if (segs[p].fst + segs[p].snd == i) {
				best = max(best, segs[p].snd);
				p++;
			} else if (segs[p].fst <= i) {
				cur = (i - segs[p].fst + 1);
			}
		}	
//		cerr << best << " " << cur << '\n';
		tree[tSize + i] = max(best, cur);
	}
//	cerr << '\n';
	fornr(i, tSize) {
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
	ll ans = 0;
	p = 0;
	forn(i, n) {
		ans += tree[1];
//		cerr << ans << '\n';
		if (p < sz(segs)) {
			if (segs[p].fst + segs[p].snd == i) {
				p++;
			} else if (segs[p].fst <= i) {
				if (segs[p].fst == i) {
					drop(segs[p].snd);
		//			cerr << "DROPPED\n";
				}

				int curLen = segs[p].fst + segs[p].snd - i;
		//		cerr << "curLen " << curLen << '\n';
				int startPos = getLeftest(1, 0, tSize, curLen - 1);
				if (startPos == INF) {
					startPos = n;
				} else {
					startPos += curLen - 1;
				}
		//		cerr << "startPos " << startPos << '\n';
				subseg(1, 0, tSize, i, startPos);
		//		cerr << "HERE\n";
			}
		}
	}
	cout << ans << '\n';
    return 0;
}