#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 55;
const int MAXQ = 9782969;

const string choice[3] = {"MW", "LW", "LM"};

struct state {
	int a[3];

	state() {
		a[0] = a[1] = a[2] = 0;
	}
};

struct event {
	state s;
	int mask, type;
		
	event(state _s = state(), int _mask = 0, int _type = 0) {
		s = _s;
		mask = _mask;
		type = _type;
	}
};

bool operator<(event a, event b) {
	if (a.s.a[0] - a.s.a[1] != b.s.a[0] - b.s.a[1])
		return a.s.a[0] - a.s.a[1] < b.s.a[0] - b.s.a[1];	
	return a.s.a[1] - a.s.a[2] < b.s.a[1] - b.s.a[2];	
}

bool operator!=(event a, event b) {
	return (a.s.a[0] - a.s.a[1] != b.s.a[0] - b.s.a[1]) 
		|| (a.s.a[1] - a.s.a[2] != b.s.a[1] - b.s.a[2]);	
}

int n, M;
int a[MAXN][3];
state zero;
int sz;
event q[MAXQ];
int res, resMask[2];
int cur, curMask[2], curVal[2];

void gen(int L, int R, state cur, int mask, int type) {
	if (L == R) {
		q[sz++] = event(cur, mask, type);
		return;
	}
	
	state cur2;
	forn(i, 3) {
		cur2 = cur;
		forn(j, 3)
			if (i != j)
				cur2.a[j] += (type == 0 ? 1 : -1) * a[L][j];
		gen(L + 1, R, cur2, mask * 3 + i, type); 	
	}
}

void encode(int mask, int len) {
	if (len == 0)	
		return;
		
	encode(mask / 3, len - 1);
	cout << choice[mask % 3] << '\n';
}

int main() {
	
	cin >> n;
	forn(i, n)
		forn(j, 3)
			cin >> a[i][j];
			
	if (n == 1) {
		forn(i, 3)
			if (a[0][(i + 1) % 3] == 0 && a[0][(i + 2) % 3] == 0) {
				cout << choice[i] << '\n';
				return 0;	
			}
		cout << "Impossible\n";
		return 0;
	}
	
	zero = state();
	M = n / 2;
	gen(0, M, zero, 0, 0);
	gen(M, n, zero, 0, 1);
	
	sort(q, q + sz);
	int L = 0;
	
	res = -INF;
	resMask[0] = resMask[1] = -1;
	
	forab(i, 1, sz + 1)
		if (i == sz || q[L] != q[i]) {
			//cout << "IN CLASS:\n";
			
			cur = -INF;
			curMask[0] = curMask[1] = -1;
	        curVal[0] = -INF;
	        curVal[1] = INF;

			for (int j = L; j < i; j++) {
				/*
				cout << "---\n";
				db(q[j].type);
				forn(i, 3)
					db(q[j].s.a[i]);
		        */
				if (q[j].type == 0) {
					if (curVal[0] < q[j].s.a[0]) {
						curVal[0] = q[j].s.a[0];
						curMask[0] = q[j].mask;
					}
				} else {
					if (curVal[1] > q[j].s.a[0]) {
						curVal[1] = q[j].s.a[0];
						curMask[1] = q[j].mask;
					}
				}
			}
			
			if (curMask[0] != -1 && curMask[1] != -1) {
				if (res < curVal[0] - curVal[1]) {
					res = curVal[0] - curVal[1];
					forn(j, 2)
						resMask[j] = curMask[j];
				}
			}
			
			L = i;
		}
	
	
	if (resMask[0] == -1)
		cout << "Impossible\n";
	else {
		//cout << res << '\n';
		encode(resMask[0], M - 0);	
		encode(resMask[1], n - M);	
	}
	
	return 0;
}