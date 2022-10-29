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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 400500;

int n, m, s, d;
int a[MAXN];
int num;
pii segs[MAXN], curSeg;
vector<pii> go;
                  
int main() {

	scanf("%d%d%d%d", &n, &m, &s, &d);
	forn(i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);
	
	num = 0;
	curSeg = {a[0], a[0]};
	
	for (int i = 1; i <= n; i++)
		if ((i == n) || (a[i] - a[i - 1] >= s + 2)) {
			segs[num] = curSeg;
			num++;
			if (i != n)
				curSeg = {a[i], a[i]};
		} else {
			curSeg.Y = a[i];	
		}
	/*
	forn(i, num)
		cout << segs[i].X << ' ' << segs[i].Y << '\n';
	*/	
	int pos = 0;
	forn(i, num) {
		if (segs[i].X - pos - 1 >= s) {
		    //run
		    go.pb({0, segs[i].X - pos - 1});
		    pos = segs[i].X - 1;
		    
		    //jump
		    if (segs[i].Y + 1 - pos > d) {
		    	cout << "IMPOSSIBLE\n";
				return 0;	
		    } else {
		    	go.pb({1, segs[i].Y + 1 - pos});
		    	pos = segs[i].Y + 1;
		    }
		} else {
			cout << "IMPOSSIBLE\n";
			return 0;	
		}
	}
	
	if (pos < m) {
		go.pb({0, m - pos});
		pos = m;
	}
	
	for (auto p: go) {
		if (p.X == 0)
			cout << "RUN ";
		else
			cout << "JUMP ";
		printf("%d\n", p.Y);
	}
	
	return 0;
}