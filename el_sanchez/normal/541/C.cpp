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
const int MAXN = 211;       

int n, len, maxlen;
int a[MAXN];
int primes[MAXN], used[MAXN], cycled[MAXN];
vector<ll> lens;
ll sum, ans, add;

ll gcd(ll a, ll b) {
   return b ? gcd(b, a % b) : a;
}

int main() {
    /*
    add = 0;
    sum = 1;
    for (int i = 2; i < MAXN; i++) {
    	if (!primes[i]) {
    		if (add + i > 200)
    			break;
    		add += i;
    		sum *= i;
    		cout << sum << ' ' << add << '\n';

    		for (int j = i; j < MAXN; j += i)
    			primes[j] = 1;	
    	}
    }
    */
    
    cin >> n;
    forn(i, n) {
    	cin >> a[i];
    	a[i]--;	
    }
    
    //cycle
    forn(i, n) {
    	int j = i;
    	memset(used, 0, sizeof(used));
    	for (int iter = 1; iter < 400; iter++) {
    		used[j] = 1;
    		j = a[j];	
    		if (j == i) {
    			forn(k, n)
    				cycled[k] |= used[k];
    			lens.pb(iter);
    			break;
    		}
    	}             
    }
    
    //go
    maxlen = 0;
    forn(i, n) {
    	int j = i;
    	if (cycled[i])
    		continue;
    	
    	for (int iter = 1; iter < 400; iter++) {
    		j = a[j];	
    		if (cycled[j]) {
    			maxlen = max(maxlen, iter);
    			break;
    		}
    		assert(iter != 399);
    	}	
    }
    
    ans = 1;
    for (auto x: lens) {
    	ll g = gcd(ans, x);
    	ans /= g;
    	ans *= x;		
    }
    ll val = ans;
    while (ans < maxlen) {
    	ans += val;	
    }
    
    cout << ans;    	
    
    return 0;
}