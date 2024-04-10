#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

vector<string> A;
int H, W;

void solve() {
	cin >> H >> W;
	A.resize(H);
	for(int i = 0; i < H; i++)
		cin >> A[i];
	
	vector<pii> V;
	for(int i = H; i--;) {
		for(int j = W; j--;) {
			if('L' == A[i][j])
				V.eb(i, j);
			if('.' == A[i][j]) {
				int c = 0;
				for(int dr = 4; dr--;) {
					int ny = i+dy[dr], nx = j+dx[dr];
					if(ny < 0 || nx < 0 || H <= ny || W <= nx) continue;
					if('#' != A[ny][nx]) c++;
				}
				A[i][j] = '0' + c;
			}
		}
	}

	while(!V.empty()) {
		int y, x; tie(y, x) = V.back();
		V.pop_back();

		for(int dr = 4; dr--;) {
			int ny = y+dy[dr], nx = x+dx[dr];
			if(ny < 0 || nx < 0 || H <= ny || W <= nx) continue;
			char &c = A[ny][nx];
			if('0' <= c && c <= '4') {
				c--;
				if(c <= '1') {
					c = 'x';
					V.eb(ny, nx);
				}
			}
		}
	}

	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			char c = A[i][j];
			if('x' == c) putchar('+');
			else if('L' == c) putchar('L');
			else if('#' == c) putchar('#');
			else putchar('.');
		}
		putchar('\n');
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	while(T--) solve();

	return 0;
}