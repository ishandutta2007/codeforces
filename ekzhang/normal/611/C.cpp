#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXH 505
#define MAXW 505
int H, W, Q;
bool grid[MAXH][MAXW];
bool domud[MAXH][MAXW];
bool domlr[MAXH][MAXW];
int fenwickud[MAXH][MAXW];
int fenwicklr[MAXH][MAXW];

void updateud(int x, int y, int val) {
	for (int x0 = x + 1; x0 <= MAXH; x0 += x0 & -x0) {
		for (int y0 = y + 1; y0 <= MAXW; y0 += y0 & -y0) {
			fenwickud[x0][y0] += val;
		}
	}
}

int queryud(int x, int y) {
	int ans = 0;
	for (int x0 = x + 1; x0 > 0; x0 -= x0 & -x0) {
		for (int y0 = y + 1; y0 > 0; y0 -= y0 & -y0) {
			ans += fenwickud[x0][y0];
		}
	}
	return ans;
}

void updatelr(int x, int y, int val) {
	for (int x0 = x + 1; x0 <= MAXH; x0 += x0 & -x0) {
		for (int y0 = y + 1; y0 <= MAXW; y0 += y0 & -y0) {
			fenwicklr[x0][y0] += val;
		}
	}
}

int querylr(int x, int y) {
	int ans = 0;
	for (int x0 = x + 1; x0 > 0; x0 -= x0 & -x0) {
		for (int y0 = y + 1; y0 > 0; y0 -= y0 & -y0) {
			ans += fenwicklr[x0][y0];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < W; j++) {
			grid[i][j] = (S[j] == '.');
		}
	}

	for (int i = 0; i < H - 1; i++) {
		for (int j = 0; j < W; j++) {
			if (grid[i][j] && grid[i + 1][j]) {
				domud[i][j] = true;
				updateud(i, j, 1);
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W - 1; j++) {
			if (grid[i][j] && grid[i][j + 1]) {
				domlr[i][j] = true;
				updatelr(i, j, 1);
			}
		}
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;c1--;r2--;c2--;
		int ans = queryud(r2 - 1, c2);
		// error(i, ans);
		ans -= queryud(r1 - 1, c2);
		// error(ans);
		ans -= queryud(r2 - 1, c1 - 1);
		// error(ans);
		ans += queryud(r1 - 1, c1 - 1);
		// error(ans);
		ans += querylr(r2, c2 - 1);
		// error(ans);
		ans -= querylr(r1 - 1, c2 - 1);
		// error(ans);
		ans -= querylr(r2, c1 - 1);
		// error(ans);
		ans += querylr(r1 - 1, c1 - 1);
		// error(ans);
		cout << ans << '\n';
	}

	cout.flush();
	return 0;
}