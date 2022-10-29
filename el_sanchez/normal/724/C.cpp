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
const int MAXN = 400000;
const int C = 100500;

const pii dir[4] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

int n, m, k;
vi classes[2][MAXN];
pii a[MAXN];
bool used[MAXN];
ll ans[MAXN];

bool borderX(int x) {
	return (x == 0 || x == n);
}

bool borderY(int y) {
	return (y == 0 || y == m);
}

bool border(pii a) {
	return borderX(a.X) && borderY(a.Y);
}

int main() {

	cin >> n >> m >> k;
	forn(i, k) {
		scanf("%d%d", &a[i].X, &a[i].Y);
		classes[0][a[i].X - a[i].Y + C].pb(i);
		classes[1][a[i].X + a[i].Y + C].pb(i);		
	}
	
	memset(used, 0, sizeof(used));
	memset(ans, -1, sizeof(ans));
	
	pii cur = {0, 0};
	int d = 0;
	int dist = 0;
	ll T = 0;
	
	while (true) {
	    dist = INF;
	    dist = min(dist, (dir[d].X > 0 ? (n - cur.X) : cur.X));
	    dist = min(dist, (dir[d].Y > 0 ? (m - cur.Y) : cur.Y));
	    
	    int id = (d / 2);
	    int cf = (id == 0 ? (cur.X - cur.Y + C) : (cur.X + cur.Y + C));
	    for (auto i: classes[id][cf]) {
	    	if (used[i])
	    		continue;

	    	used[i] = 1;
	    	assert(abs(cur.X - a[i].X) == abs(cur.Y - a[i].Y));
	    	ans[i] = T + abs(cur.X - a[i].X);                  	    	
	    }
		
	    T += dist;
	    
	    cur.X += dist * dir[d].X;
	    cur.Y += dist * dir[d].Y;
	    
		if (border(cur))
			break;	

		assert(borderX(cur.X) || borderY(cur.Y));
			
		pii fd = dir[d];
		if (borderX(cur.X))
			fd.X *= -1;
		else if (borderY(cur.Y))
			fd.Y *= -1;
			
		forn(i, 4)
			if (dir[i] == fd)
				d = i;
	}
	//cout << T << '\n';
	
	forn(i, k)
		printf("%I64d\n", ans[i]);
	
	return 0;
}