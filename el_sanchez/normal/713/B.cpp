#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9; 
//const int N = (1 << 16);

pii operator+(pii a, pii b) {
	return {a.X + b.X, a.Y + b.Y};	
}

pii operator*(pii a, int k) {
	return {a.X * k, a.Y * k};	
}

pair<pii, pii> norm(pair<pii, pii> a) {
	if (a.X.X > a.Y.X)
		swap(a.X.X, a.Y.X);
	if (a.X.Y > a.Y.Y)
		swap(a.X.Y, a.Y.Y);
	a.X.X++;
	a.X.Y++;
	a.Y.X++;
	a.Y.Y++;
	return a;			
}

map<pair<pii, pii>, int> lib;

int Q = 0;

int ask(pair<pii, pii> a) {
	a = norm(a);
	if (lib.find(a) != lib.end())
		return lib[a];

	Q++;	
	assert(Q <= 200);
	printf("? %d %d %d %d\n", a.X.X, a.X.Y, a.Y.X, a.Y.Y);
	cout.flush();
	int k;
	cin >> k;
	lib[a] = k;
	return k;	
}

bool inside(pair<pii, pii> a, pair<pii, pii> b) {
	return b.X.X <= a.X.X && a.Y.X <= b.Y.X && b.X.Y <= a.X.Y && a.Y.Y <= b.Y.Y;
}

int N;
pii F;
set<int> rx, ry;
vi cx, cy;
set<pair<pii, pii>> temps, results;

int main() {

	cin >> N;	
	
	pii delta[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};    
	pii S[4] = {{N - 1, 0}, {0, 0}, {0, N - 1}, {0, 0}};

	lib[{{1, 1}, {N, N}}] = 2;
	
	int L, R, M;
	forn(i, 4) {
		L = -1;
		R = N - 1;
		
		forn(d, 2) {
			while (R - L > 1) {
				M = (L + R) >> 1;
				F = S[i] + delta[i] * M;
				
				if (i <= 1) {
					F.Y = N - 1;
				} else {
					F.X = N - 1;
				}
				
				int res = ask({S[i], F});
				if (res != d)
					R = M;
				else
					L = M;
			}
		
			F = S[i] + delta[i] * R;
			if (i <= 1) {
				F.Y = N - 1;
			} else {
				F.X = N - 1;
			}   			
				
			if (i <= 1) {
				rx.insert(F.X);
			} else {
				ry.insert(F.Y);	
			}
			
			if (ask({S[i], F}) != 1)
				break;
			
			L = R;
			R = N - 1;
		}
	}
	
	//bf
	assert(rx.size() <= 4);
	assert(ry.size() <= 4);
	
	for (auto x: rx)
		cx.pb(x);
	for (auto y: ry)
		cy.pb(y);
		
	for (int i = 0; i < (int)cx.size(); i++)
		for (int j = i + (cx.size() == 4); j < (int)cx.size(); j++)
			for (int i2 = 0; i2 < (int)cy.size(); i2++)
				for (int j2 = i2 + (cy.size() == 4); j2 < (int)cy.size(); j2++) {
					if (ask({{cx[i], cy[i2]}, {cx[j], cy[j2]}}) == 1)
						temps.insert({{cx[i], cy[i2]}, {cx[j], cy[j2]}});					
				}		
	
	for (auto r: temps) {
		bool ok = 1;
		for (auto q: temps)
			if (r != q && inside(q, r))
				ok = 0;
		if (ok)
			results.insert(norm(r));
	}
	
	assert(results.size() == 2);
	cout << "!";
	for (auto r: results) {
		printf(" %d %d %d %d", r.X.X, r.X.Y, r.Y.X, r.Y.Y);
	}
	cout << '\n';
	cout.flush();
	
	return 0;
}