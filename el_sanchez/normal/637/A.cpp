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
const int MAXN = 1000500;

int n, k;
int curMax, curId;
int cnt[MAXN];
                
int main() {

	cin >> n;
	
	curMax = 0;
	curId = -1;
	memset(cnt, 0, sizeof(cnt));
	
	forn(i, n) {
		cin >> k;
		cnt[k]++;
		if (cnt[k] > curMax) {
			curMax = cnt[k];
			curId = k;
		}
	}
	
	cout << curId << '\n';
	
	return 0;
}