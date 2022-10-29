#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second                    
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;        
const int MAXN = 200500;
const int MAXM = 500500;
      
int n, q, k, num, odd, used[MAXN], mn, a[MAXN]; 
int state[MAXM];
int primesList[MAXM][7], psz[MAXM], z;
int bits[MAXM];
ll ans, ans2, active;

int main() {

	scanf("%d%d", &n, &q);
	forn(i, n)
		scanf("%d", &a[i]);
	
	for (int i = 2; i < MAXM; i++) {
		if (psz[i] == 0) {
			for (int j = i; j < MAXM; j += i) {
				primesList[j][psz[j]++] = i;
				//cerr << j << '\n';
				assert(psz[j] <= 7);
			}		
		}
	}
	
	forn(i, MAXM) {
		int mask = i;
		while (mask > 0) {
			if (mask & 1)
				bits[i]++;
			mask >>= 1;
		}
	}	
	ans = 0;
	active = 0;
	forn(i, q) {
	   	scanf("%d", &k);
	   	k--;
	   	
	   	num = a[k];
	   	
	   	if (!used[k])
	   		z = 1;
	   	else
	   		z = -1;
	   		
   		int maxmask = 1 << psz[num];
   		for (int mask = 1; mask < maxmask; mask++) {
   			mn = 1;
   			forn(d, psz[num])
				if ((mask >> d) & 1)
					mn *= primesList[num][d];
						   			
   			odd = bits[mask] & 1;
   			if (used[k])
   				state[mn] += z;
   			if (odd)
   				ans = ans + state[mn] * z;	
   			else
   				ans = ans - state[mn] * z;
   			if (!used[k])
   				state[mn] += z;
   		}
	   	
	   	used[k] ^= 1;
	   	active += z;
	   	ans2 = active * (active - 1) / 2 - ans;
		printf("%I64d\n", ans2);
	}
	
	return 0;
}