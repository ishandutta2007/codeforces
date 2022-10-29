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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 500500;

int n, a, b, T;
string s;
int watch[MAXN];
ll pTime[MAXN], restTime;
int ans;
int ptr, ptr2;

void updAns() {
	//cout << ptr << ' ' << ptr2 << ' ' << restTime << '\n';
	
	if (ptr2 != -1)
		ans = max(ans, (ptr + 1) + (n - ptr2));
	else
		ans = max(ans, (ptr + 1));
	assert(ans <= n);			
}

int main() {
        
	scanf("%d%d%d%d", &n, &a, &b, &T);
	cin >> s;
	forn(i, n)
		watch[i] = (s[i] == 'w' ? b : 0) + 1;
		
	ans = 0;
	
	forn(iii, 2) {
		pTime[0] = watch[0];
		for (int i = 1; i < n; i++)
			pTime[i] = pTime[i - 1] + a + watch[i];
			
		ptr = n - 1;
		while (ptr >= 0 && pTime[ptr] > T) {
			ptr--;	
		}

		if (ptr >= 0) {
			if (ptr == n - 1) {
				cout << n << '\n';
				return 0;	
			}
			
			restTime = T - pTime[ptr];
			ptr2 = -1;

			if (restTime >= 1ll * (ptr + 1) * a + watch[n - 1]) {
				ptr2 = n - 1;
				restTime -= 1ll * (ptr + 1) * a + watch[n - 1];	
			}
			
			if (ptr2 != -1) {
				while (ptr2 > 0 && restTime >= a + watch[ptr2 - 1]) {
					restTime -= a + watch[ptr2 - 1];
					ptr2--;
				}
			}
			
			updAns();
			
			while (true) {
				restTime += watch[ptr] + a;
				if (ptr2 != -1)
					restTime += a;
					
				ptr--;
				if (ptr < 0)
					break;

				if (ptr2 == -1) {
					if (restTime >= 1ll * (ptr + 1) * a + watch[n - 1]) {
						ptr2 = n - 1;
						restTime -= 1ll * (ptr + 1) * a + watch[n - 1];	
					}
				}
				
				if (ptr2 != -1) {
					while (ptr2 > 0 && restTime >= a + watch[ptr2 - 1]) {
						restTime -= a + watch[ptr2 - 1];
						ptr2--;
					}
				}
				
				updAns();
			}
		}
		
		reverse(watch + 1, watch + n);	
	}
	
	cout << ans << '\n';
	
	return 0;	
}