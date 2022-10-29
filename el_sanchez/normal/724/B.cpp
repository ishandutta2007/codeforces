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
const int MAXN = 33;

int n, m;
int a[MAXN][MAXN];
bool ans;

void swapc(int j1, int j2) {
	forn(i, n)
		swap(a[i][j1], a[i][j2]);	
}

bool calc() {
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		forn(j, m)
			if (a[i][j] != j)
				cnt++;
				
		if (cnt > 2)
			return 0;
	}
	
	return 1;
}

int main() {

	cin >> n >> m;
	forn(i, n)
		forn(j, m) {
			cin >> a[i][j];
			a[i][j]--;
		}

	ans = 0;
		
	ans |= calc();
	for (int i = 0; i < m; i++)
		for (int i2 = i + 1; i2 < m; i2++) {
			swapc(i, i2);
			ans |= calc();
			swapc(i, i2);	
		}
	
	cout << (ans ? "YES\n" : "NO\n");
		
	return 0;
}