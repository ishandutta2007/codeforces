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

int n;
string s;
int dir[MAXN], used[MAXN];

int main() {

	cin >> n;
	cin >> s;
	forn(i, n) {
		scanf("%d", &dir[i]);
		if (s[i] == '<')
			dir[i] *= -1;
	}
	
	int v = 0;
	while (!used[v]) {
		used[v] = 1;
		v = v + dir[v];
		if (!(0 <= v && v < n)) {
			cout << "FINITE\n";	
			return 0;
		}
	}
	
	cout << "INFINITE\n";
	return 0;
}