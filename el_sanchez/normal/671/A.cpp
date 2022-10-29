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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 100500;
    
bool eq(ld a, ld b) {
	return (fabs(a - b) < eps);
}

struct pt {
	ld x, y;
	pt(): x(0), y(0) {}
	pt(ld _x, ld _y) {
		x = _x, y = _y;
	}
	
	void read() {
		int rx, ry;
		scanf("%d%d", &rx, &ry);
		x = rx;
		y = ry;
	}
	
	void print() {
		cout << x << ' ' << y << endl;	
	}
	
	friend bool eq(pt a, pt b) {
		return eq(a.x, b.x) && eq(a.y, b.y);
	}
	
	friend bool operator==(pt a, pt b) {
		return a.x == b.x && a.y == b.y;
	}
	
	friend bool operator<(pt a, pt b) {
		return (a.x < b.x) || (eq(a.x, b.x) && (a.y < b.y));
	}
	
	friend pt operator-(pt p1, pt p2) {
		return pt(p1.x - p2.x, p1.y - p2.y);
	}

	friend pt operator+(pt p1, pt p2) {
		return pt(p1.x + p2.x, p1.y + p2.y);
	}

	friend pt operator*(pt a, ld b) {
		return pt(a.x * b, a.y * b);
	}

	friend pt operator/(pt a, ld b) {
		return pt(a.x / b, a.y / b);
	}

	ld len() {
		return sqrt(.0 + x * x + y * y);
	}
	
	ld dist(pt p) {
		return (*this - p).len();
	}
};

int x, y;
pt a[2], c;
int n;
pt p[MAXN];
ld dist[2][MAXN];
int minId[2][2];
ld ans;

int main() {
             
	a[0].read();
	a[1].read();
	c.read();
	cin >> n;
	forn(i, n)
		p[i].read();

	ans = 0;
	cout.precision(20);
	
	if (n == 1) {
		ans = min(a[0].dist(p[0]), a[1].dist(p[0])) + p[0].dist(c);
		cout << (double)ans << '\n';
		return 0;	
	}
	
	ld sum = 0;
	forn(i, n)
		sum += 2.0 * c.dist(p[i]);	

	//cout << (double)sum << '\n';
	
	ans = 1E100;
	
	memset(minId, -1, sizeof(minId));
		
	forn(i, 2) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = -2.0 * c.dist(p[j]) + a[i].dist(p[j]) + p[j].dist(c);
			if (minId[i][0] == -1 || dist[i][minId[i][0]] > dist[i][j]) {
				minId[i][1] = minId[i][0];
				minId[i][0] = j;	
			} else if (minId[i][1] == -1 || dist[i][minId[i][1]] > dist[i][j]) {
				minId[i][1] = j;	
			}
		}
	}
	
	//cout << minId[0][0] << '\n';
	//cout << minId[1][0] << '\n';
	
	//choose
	
	//one:
	forn(i, 2) {
		int id = minId[i][0];
		ans = min(ans, sum + dist[i][id]);
	}
	
	//two:
	forn(i, 2) {
		forn(j, 2) {
			int id0 = minId[0][i];
			int id1 = minId[1][j];
			if (id0 != id1)
				ans = min(ans, sum + dist[0][id0] + dist[1][id1]);
		}
	}
	
	cout << (double)ans << '\n';
	
	return 0;
}