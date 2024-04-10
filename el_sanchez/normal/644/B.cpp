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
const int MAXN = 200500;

int n, b, a, c;
ll t[MAXN], d[MAXN];
ll ans[MAXN], T;
set<pair<ll, int>> queries;
queue<int> q;
bool busy;            

int main() {
	
	scanf("%d%d", &n, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &c);
		t[i] = a;
		d[i] = c;
		queries.insert({t[i], i});	
	}

	memset(ans, -1, sizeof(ans));
	
	T = 0;
	busy = 0;
	while (!queries.empty()) {
		auto p = *queries.begin();
		queries.erase(p);
		int id = p.Y;
		
		//cout << p.X << ' ' << p.Y << '\n';
		
		if (!busy) {
			busy = 1;
			T = p.X;
			queries.insert({T + d[id], -id});
		} else {
			T = p.X;
			if (id < 0) {
				id *= -1;
				ans[id] = p.X;
				if (!q.empty()) {
					int nId = q.front();	
					queries.insert({T + d[nId], -nId});
					q.pop();
				} else
					busy = 0;
			} else {
				if ((int)q.size() < b) {
					q.push(id);
				} else {
					ans[id] = -1;	
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		printf("%I64d ", ans[i]);
	cout << '\n';
		
	return 0;
}