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
const int MAXN = 150500;
    
int n, k, q;
int t[MAXN];
set<pii> friends;

int main() {
	 
	cin >> n >> k >> q;
	forn(i, n)
		scanf("%d", &t[i]);
	forn(ii, q) {
		int a, b;
		scanf("%d%d", &a, &b);
		b--;

		if (a == 1) {
			friends.insert({t[b], b});
			while ((int)friends.size() > k) {
				auto p = *friends.begin();
				friends.erase(p);
			}
		} else {
			bool ok = 0;
			for (auto p: friends)
				if (p.Y == b)	
					ok = 1;
			cout << (ok ? "YES\n" : "NO\n");
		}
	}
	
	return 0;
}