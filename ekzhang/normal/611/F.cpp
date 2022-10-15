#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MOD 1000000007

int N;
LL H, W;
string S;
int best;
int x = 0, y = 0, ax = 0, ix = 0, ay = 0, iy = 0;
vector<pair<int, char> > imp;
LL ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> H >> W >> S;
	for (int i = 0; i < N; i++) {
		// first runthrough
		if (S[i] == 'U') {
			x--;
			if (x < ix && ax - ix + 1 <= H) {
				ix--;
				ans += (i + 1) * (W - (ay - iy));
				ans %= MOD;
			}
		}
		else if (S[i] == 'D') {
			x++;
			if (x > ax && ax - ix + 1 <= H) {
				ax++;
				ans += (i + 1) * (W - (ay - iy));
				ans %= MOD;
			}
		}
		else if (S[i] == 'L') {
			y--;
			if (y < iy && ay - iy + 1 <= W) {
				iy--;
				ans += (i + 1) * (H - (ax - ix));
				ans %= MOD;
			}
		}
		else {
			y++;
			if (y > ay && ay - iy + 1 <= W) {
				ay++;
				ans += (i + 1) * (H - (ax - ix));
				ans %= MOD;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		// second runthrough
		if (S[i] == 'U') {
			x--;
			if (x < ix && ax - ix + 1 <= H) {
				ix--;
				ans += (N + i + 1) * (W - (ay - iy));
				ans %= MOD;
				imp.push_back({i + 1, 'U'});
			}
		}
		else if (S[i] == 'D') {
			x++;
			if (x > ax && ax - ix + 1 <= H) {
				ax++;
				ans += (N + i + 1) * (W - (ay - iy));
				ans %= MOD;
				imp.push_back({i + 1, 'D'});
			}
		}
		else if (S[i] == 'L') {
			y--;
			if (y < iy && ay - iy + 1 <= W) {
				iy--;
				ans += (N + i + 1) * (H - (ax - ix));
				ans %= MOD;
				imp.push_back({i + 1, 'L'});
			}
		}
		else {
			y++;
			if (y > ay && ay - iy + 1 <= W) {
				ay++;
				ans += (N + i + 1) * (H - (ax - ix));
				ans %= MOD;
				imp.push_back({i + 1, 'R'});
			}
		}
	}

	// successive runthroughs
	for (LL r = 3; ax - ix + 1 <= H && ay - iy + 1 <= W; r++) {
		// error(ix, ax, iy, ay, ans);
		if (imp.empty()) {
			cout << -1 << endl;
			return 0;
		}
		for (pair<int, char> p : imp) {
			if (p.second == 'U' && ax - ix + 1 <= H) {
				ix--;
				ans += (N * (r - 1) + p.first) * (W - (ay - iy));
				ans %= MOD;
			}
			if (p.second == 'D' && ax - ix + 1 <= H) {
				ax++;
				ans += (N * (r - 1) + p.first) * (W - (ay - iy));
				ans %= MOD;
			}
			if (p.second == 'L' && ay - iy + 1 <= W) {
				iy--;
				ans += (N * (r - 1) + p.first) * (H - (ax - ix));
				ans %= MOD;
			}
			if (p.second == 'R' && ay - iy + 1 <= W) {
				ay++;
				ans += (N * (r - 1) + p.first) * (H - (ax - ix));
				ans %= MOD;
			}
		}
	}

	cout << ans << endl;
	return 0;
}