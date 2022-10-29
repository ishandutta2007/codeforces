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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

struct pt {
	ll x, y;
	pt(): x(0), y(0) {}
	pt(ll _x, ll _y) {
		x = _x, y = _y;
	}
};

bool operator==(pt a, pt b) {
	return a.x == b.x && a.y == b.y;
}

inline bool operator<(pt a, pt b) {
	return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
}

pt operator-(pt p1, pt p2) {
	return pt(p1.x - p2.x, p1.y - p2.y);
}

pt operator+(pt p1, pt p2) {
	return pt(p1.x + p2.x, p1.y + p2.y);
}

pt operator*(pt a, ll b) {
	return pt(a.x * b, a.y * b);
}

ll operator*(pt p1, pt p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

ll operator%(pt p1, pt p2) {
	return p1.x * p2.y - p2.x * p1.y;
}

int n, x, y;
pt a[MAXN];
int id[3], skip, sign[3];

int main() {

	scanf("%d", &n);
	forn(i, n) {
		scanf("%d%d", &x, &y);
		a[i] = pt(x, y);
		//cout << a[i].x << ' ' << a[i].y << '\n';
	}
	
	id[0] = 0;
	id[1] = 1;
	id[2] = 2;
	while ((a[id[1]] - a[id[0]]) % (a[id[2]] - a[id[0]]) == 0) {
		id[2]++; 
		assert(id[2] != n);
	}
	
	skip = id[2];
	
	for (int i = 2; i < n; i++) {
		if (i == skip)
			continue;

		bool ok = 0;
		for (int j = 0; j < 3; j++) {
			pt A = a[id[j]];
			pt B = a[id[(j + 1) % 3]];
			if (((B - A) % (a[i] - A) == 0) && ((B - A) * (a[i] - A) > 0) && ((A - B) * (a[i] - B) > 0)) {
				id[j] = i;
				ok = 1;
				break;	
			}
		}
		
		if (ok)
			continue;
			
		for (int j = 0; j < 3; j++) {
			sign[j] = ((a[id[(j + 1) % 3]] - a[id[j]]) % (a[i] - a[id[j]])) > 0; 	
		}
		
		if (sign[0] == sign[1] && sign[1] == sign[2]) {
			id[0] = i;	
		}
	}
	
	cout << id[0] + 1 << ' ' << id[1] + 1 << ' ' << id[2] + 1 << '\n';
	
	return 0;
}