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
const int INF = (int)1e9;
const int MAXN = 1000500;

int n, k;
vector<pii> edges;

int main() {

	while (cin >> n >> k) {
		if (n == 2) {
			cout << -1 << '\n';
		} else if (n == 3) {
			cout << -1 << '\n';
		} else if (n == 4) {
			if (k == 3) {
				printf("3\n");
				printf("1 2\n");
				printf("2 3\n");
				printf("3 4\n");
			} else {
				cout << -1 << '\n';
			}
		} else {
			if (k == 2) {
				printf("%d\n", n - 1);
				forn(i, n - 1) {
					printf("%d %d\n", i + 1, i + 2);	
				}
			} else if (k == 3) {
				edges.clear();
				edges.pb({n - 3, n - 2});
				edges.pb({n - 2, n - 1});
				for (int i = 0; i < n - 2; i++) {
					for (int j = i + 1; j < n - 2; j++) {
						edges.pb({i, j});						
					}
				}
				
				cout << edges.size() << '\n';
				for (auto e: edges) {
					printf("%d %d\n", e.X + 1, e.Y + 1);	
				}
			} else {
				cout << -1 << '\n';	
			}
		}
	}
    			
	return 0;
}