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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 5050;

int n, k, a[4];
int path[MAXN], used[MAXN];

int main() {

	cin >> n >> k;
	if (n == 4) {
		cout << -1 << '\n';
		return 0;
	}
	if (k < n + 1) {
		cout << -1 << '\n';
		return 0;
	}
	
	forn(i, 4) {
		cin >> a[i];
		a[i]--;
		used[a[i]] = 1;
	}
	
	path[0] = a[0];
	path[1] = a[2];
	path[n - 2] = a[3];
	path[n - 1] = a[1];
	
	int ptr = 0;
	for (int i = 2; i < n - 2; i++) {
		while (ptr < n && used[ptr])
			ptr++;
		assert(ptr < n);
		path[i] = ptr;
		used[ptr] = 1;
		ptr++;	
	}
	
	forn(i, n)
		cout << path[i] + 1 << " \n"[i == n - 1];
		
	cout << path[1] + 1 << ' ' << path[0] + 1 << ' ';
	for (int i = 2; i < n - 2; i++)
		cout << path[i] + 1 << ' ';
	cout << path[n - 1] + 1 << ' ' << path[n - 2] + 1 << '\n';		
	
	return 0;
}