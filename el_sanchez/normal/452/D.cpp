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
const int MAXN = 100500;
    
int k;
int n[3], t[3];
int last;
queue<int> q[3], rest[4];

int main() {

	cin >> k;
	forn(i, 3)
		cin >> n[i];
	forn(i, 3)
		cin >> t[i];

	forn(i, 3)
		forn(j, n[i])
			q[i].push(0);
	forn(i, k)
		rest[0].push(0);

	last = 0;
	while ((int)rest[3].size() < k) {
		int id = -1;
		forn(i, 3)
			if (!rest[i].empty() && (id == -1 || max(rest[id].front(), q[id].front()) > 
												 max(rest[i].front(), q[i].front())))
				id = i;

		assert(id != -1);

		int T = max(rest[id].front(), q[id].front());
		
		rest[id].pop();
		rest[id + 1].push(T + t[id]);

		q[id].pop();
		q[id].push(T + t[id]);
		last = max(last, T + t[id]); 
	}
	
	cout << last << '\n'; 	
	
	return 0;	
}