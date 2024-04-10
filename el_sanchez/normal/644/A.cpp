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
const int MAXN = 105;

int n, a, b;
int t[MAXN][MAXN];
                
int main() {

	cin >> n >> a >> b;
	
	if (n > a * b) {
		cout << -1 << '\n';
		return 0;	
	}
	
	int cnt = 1;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (!((i + j) & 1)) {
				if (cnt <= n) {
					t[i][j] = cnt;	
					cnt += 2;
				}
			}			
		}
	}
	
	cnt = 2;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if ((i + j) & 1) {
				if (cnt <= n) {
					t[i][j] = cnt;	
					cnt += 2;
				}
			}			
		}
	}
	
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%d", t[i][j]);
			cout << " \n"[j == b - 1];
		}
	}
	
	return 0;
}