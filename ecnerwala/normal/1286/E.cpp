#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 6.1e5;
int N;
int F[MAXN];
int Z[MAXN][26];

const int S = 1 << 20;
struct seg_node {
	ll sVal = 0;
	ll wVal = 0;

	ll totVal = 0;
} seg[2*S];
void update(int n) {
	seg[n].totVal = seg[n].sVal * seg[n].wVal;
	if (n < S) {
		seg[n].totVal += seg[2*n].totVal;
		seg[n].totVal += seg[2*n+1].totVal;
	}
}

void changeS(int i, int v) {
	for (int a = S+i; a; a /= 2) {
		seg[a].sVal += v;
		update(a);
	}
}

void changeW(int l, int r, int v) {
	assert(l < r);
	for (int a = S+l, b = S+r; a < b; a /= 2, b /= 2) {
		if (a & 1) {
			seg[a].wVal += v;
			update(a);
			a++;
		}
		if (b & 1) {
			--b;
			seg[b].wVal += v;
			update(b);
		}
	}
	for (int a = S+l; a; a /= 2) {
		update(a);
	}
	for (int a = S+r-1; a; a /= 2) {
		update(a);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	const ll BASE = ll(1e10);
	ll ansHi = 0;
	ll ansLo = 0;
	ll ans26 = 0;
	ll ans230 = 0;
	F[0] = -1;
	memset(Z[0], 0, sizeof(Z[0]));

	stack<pair<int, int>> bestW;
	bestW.emplace(-1, -1);

	for (int i = 0; i < N; i++) {
		char c; int w; cin >> c >> w;
		c = (c - 'a' + ans26) % 26 + 'a';
		w ^= int(ans230 & ((1 << 30) - 1));

		//cerr << "query " << c << ' ' << w << '\n';

		F[i+1] = Z[i][c - 'a'];
		Z[i][c - 'a'] = i+1;
		memcpy(Z[i+1], Z[F[i+1]], sizeof(Z[F[i+1]]));

		//cerr << "inserting " << i << '\n';
		changeS(i, +1);

		for (char d = 'a'; d <= 'z'; d++) {
			if (d == c) continue;
			assert(Z[i][d - 'a'] <= i);
			for (int state = Z[i][d - 'a']; state > 0; state = F[state]) {
				int start = i+1 - state;
				//cerr << "removing " << start << ' ' << d << '\n';
				changeS(start, -1);
			}
		}

		while (w <= bestW.top().first) {
			auto curTop = bestW.top(); bestW.pop();
			//cerr << "changeW " << bestW.top().second+1 << ' ' << curTop.second+1 << ' ' << -curTop.first << '\n';
			changeW(bestW.top().second + 1, curTop.second + 1, -curTop.first);
		}
		//cerr << "changeW " << bestW.top().second+1 << ' ' << i+1 << ' ' << w << '\n';
		changeW(bestW.top().second + 1, i+1, +w);
		bestW.emplace(w, i);

		ll a = seg[1].totVal;
		ansLo += a;
		ansHi += ansLo / BASE;
		ansLo %= BASE;

		ans26 += a;
		ans26 %= 26;

		ans230 += a;
		ans230 &= ((1 << 30) - 1);

		if (ansHi) {
			cout << setw(0) << ansHi << setfill('0') << setw(10) << ansLo << '\n';
		} else {
			cout << ansLo << '\n';
		}
	}

	return 0;
}