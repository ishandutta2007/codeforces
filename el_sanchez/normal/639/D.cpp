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
const ll LINF = 2E18;	
const int MAXN = 200500;
    
int n, k, b, c;
int t[MAXN];
int cnt[5], positions[5][MAXN];
int M, T;
multiset<ll> distances;
ll decDist, curDist, optDist, curAdd;

void add(int newT) {
	//actual:
	ll x = -decDist;

	//count to:
	x += 1ll * ((T - newT) / M) * b;
	x += 1ll * ((T - newT) % M) * c;
	
	distances.insert(-x);
	
	curDist += (x + decDist);

	while ((int)distances.size() > k) {
		multiset<ll>::iterator p = distances.begin();
		curDist -= (-(*p) + decDist);
		distances.erase(p);
	}
}

int main() {
	 
	scanf("%d%d%d%d", &n, &k, &b, &c);
	
	if (5 * c < b) {
		M = 1;
		b = c;	
	} else {
		M = 5;	
	}
	
	forn(i, n) {
		scanf("%d", &t[i]);
		t[i] += INF + 1;
	}

	sort(t, t + n);

	memset(cnt, 0, sizeof(cnt));
	
	forn(i, n) {
		forn(j, M) {
			int k = (t[i] + j) % M;
			positions[k][cnt[k]++] = t[i] + j;
		}
	}
	
	forn(i, M) {
		forn(j, cnt[i] - 1)
			assert(positions[i][j] <= positions[i][j + 1]);
		cnt[i] = unique(positions[i], positions[i] + cnt[i]) - positions[i];
	}
	
	optDist = LINF;
	forn(i, M) {
		int ptr = 0;
		distances.clear();
		curDist = 0;
		decDist = 0;
		
		for (int j = 0; j < cnt[i]; j++) {
			T = positions[i][j];
			
			if (j != 0) {
				curAdd = 1ll * ((T - positions[i][j - 1]) / M) * b;
				decDist += curAdd;
				curDist += 1ll * distances.size() * curAdd;
			}
				
			while (ptr < n && t[ptr] <= T) {
				add(t[ptr]);
				ptr++;	
			}
			
			if ((int)distances.size() == k) {
				optDist = min(optDist, curDist);	
			}
		}
	}
	
	cout << optDist << '\n';
	
	return 0;
}