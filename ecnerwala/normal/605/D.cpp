#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 2e5;

int N;
pair<pii, pii> card[MAXN];
int prv[MAXN];

pair<int, int> xvals[2 * MAXN];
pair<int, int> yvals[2 * MAXN];

const int S = 1 << 18;
int seg[S * 2];

int main() {
	ios_base::sync_with_stdio(0);

	memset(prv, -1, sizeof(prv));

	cin >> N;

	card[0] = make_pair(pii(-1, -1), pii(0, 0));
	prv[0] = 0;

	for(int i = 1; i <= N; i++) {
		cin >> card[i].A.A >> card[i].A.B >> card[i].B.A >> card[i].B.B;
	}

	for(int i = 0; i <= N; i++) {
		xvals[i] = pii(card[i].A.A, i);
		yvals[i] = pii(card[i].A.B, i);
	}
	sort(xvals, xvals + N + 1);
	sort(yvals, yvals + N + 1);
	for(int i = 0; i <= N; i++) {
		card[xvals[i].B].A.A = i;
		card[yvals[i].B].A.B = i;
	}
	for(int i = 0; i <= N; i++) {
		card[i].B.A = int(upper_bound(xvals, xvals + N + 1, pii(card[i].B.A, N + 1)) - xvals);
		card[i].B.B = int(upper_bound(yvals, yvals + N + 1, pii(card[i].B.B, N + 1)) - yvals);
	}

	//for(int i = 0; i <= N; i++) cerr << card[i].A.A << ' ' << card[i].A.B << ' ' << card[i].B.A << ' ' << card[i].B.B << '\n';
	for(int i = 0; i < 2 * S; i++) seg[i] = INF;
	for(int i = 1; i <= N; i++) {
		seg[S + i] = card[xvals[i].B].A.B;
	}
	for(int i = S - 1; i > 0; i--) {
		seg[i] = min(seg[2 * i], seg[2 * i + 1]);
	}

	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		int x = card[v].B.A;
		int y = card[v].B.B;
		x--, y--;
		// you can cast anything <= x, <= y
		for(int a = S + x; a; a /= 2) {
			if(!(a & 1)) {
				while(seg[a] <= y) {
					int b = a;
					while(b < S) {
						assert(seg[b] <= y);
						assert(seg[b] == min(seg[2 * b], seg[2 * b + 1]));
						b *= 2;
						if(!(seg[b] <= y)) b++;
						assert(seg[b] <= y);
					}
					assert(seg[b] <= y);
					//assert(b - S <= x);

					int nxt = xvals[b - S].B;
					assert(card[nxt].A.A <= x && card[nxt].A.B <= y);
					assert(prv[nxt] == -1);
					prv[nxt] = v;
					q.push(nxt);

					seg[b] = INF;
					for(b /= 2; b; b /= 2) {
						seg[b] = min(seg[2 * b], seg[2 * b + 1]);
					}
				}
				a--;
			}
		}
	}

	if(prv[N] == -1) {
		cout << -1 << '\n';
		return 0;
	}

	stack<int> res;
	for(int cur = N; cur != 0; cur = prv[cur]) {
		res.push(cur);
	}
	cout << res.size() << '\n';
	while(!res.empty()) {
		cout << res.top() << ' ';
		res.pop();
	}
	cout << '\n';

	return 0;
}