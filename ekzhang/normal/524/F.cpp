#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXLG 24
#define MAXN 1000013
#define MAXSEG 2097152
#define INF (1<<30)
int N;
string s;
struct entry {
	int nr[2], p;
} L[2 * MAXN];
int P[2][4 * MAXN], stp;
int order[MAXN];

int prefix[MAXN];
int total;
int st[MAXSEG];

char ANS[2 * MAXN];

void update(int i, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N;
	if (i < lo || i > hi) return;
	if (lo == hi) { st[node] += x; return; }
	int mid = (lo + hi) / 2;
	update(i, x, lo, mid, 2 * node + 1);
	update(i, x, mid + 1, hi, 2 * node + 2);
	st[node] = min(st[2 * node + 1], st[2 * node + 2]);
}

int query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N;
	if (e < lo || s > hi) return INF;
	if (s <= lo && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return min(query(s, e, lo, mid, 2 * node + 1),
			query(s, e, mid + 1, hi, 2 * node + 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> s;
	N = s.size();

	for (int i = 0; i < N; i++) {
		prefix[i+1] = prefix[i] + (s[i] == '(' ? 1 : -1);
		update(i + 1, prefix[i + 1]);
	}
	total = prefix[N];

	// step 1: build suffix array on s+s
	// step 2: iter, find first location
	//         that has an OK minimum
	// Done!
	for (int i = 0; i < 2 * N; i++) {
		P[0][i] = (s[i % N] == ')') + 1;
	}
	for (stp = 1; (1<<(stp-1)) < 2 * N; stp++) {
		int cnt = 1<<(stp-1);
		int t = stp % 2;
		for (int i = 0; i < 2 * N; i++) {
			L[i].nr[0] = P[!t][i];
			L[i].nr[1] = P[!t][i + cnt];
			L[i].p = i;
		}
		sort(L, L + 2 * N, [](entry a, entry b) {
			return a.nr[0] == b.nr[0] ? a.nr[1] < b.nr[1] : a.nr[0] < b.nr[0];
		});
		int cur = 1;
		for (int i = 0; i < 2 * N; i++) {
			if (i == 0 || (L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1])) {
				P[t][L[i].p] = cur;
			}
			else {
				P[t][L[i].p] = ++cur;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		order[i] = i;
	}
	stp = (stp - 1) % 2;
	sort(order, order + N, [](int a, int b) {
		return P[stp][a] < P[stp][b];
	});

	// stp = 0;
	// error(stp, P[stp][0], P[stp][1], P[stp][2]);
	// stp = 1;
	// error(stp, P[stp][0], P[stp][1], P[stp][2]);
	// stp = 2;
	// error(stp, P[stp][0], P[stp][1], P[stp][2]);
	// stp = 3;
	// error(stp, P[stp][0], P[stp][1], P[stp][2]);

	// okay suffix array algo completed, now we iterate over order[]
	int a;
	for (int i = 0; i < N; i++) {
		int idx = order[i];
		int amt = query(idx + 1, N) - prefix[idx];
		// error(amt, total - prefix[idx]);
		amt = min(amt, query(1, idx) + total - prefix[idx]);
		// error(idx, amt);

		int bound = min(total, 0);
		if (amt >= bound) {
			a = idx;
			break;
		}
	}

	int idx = 0;
	if (total < 0) {
		for (int i = 0; i < -total; i++) {
			ANS[idx++] = '(';
		}
	}
	for (int i = a; i < a + N; i++) {
		ANS[idx++] = s[i % N];
	}
	if (total > 0) {
		for (int i = 0; i < total; i++) {
			ANS[idx++] = ')';
		}
	}

	for (int i = 0; i < idx; i++) {
		cout << ANS[i];
	}
	cout << endl;
	return 0;
}