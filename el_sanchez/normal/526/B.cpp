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
const ld eps = 1e-14;
const int INF = 1E9;		                    
const int MAXN = 22222;
    
int n, k; 
ll a[MAXN], sum, d;

int main() { 
	
	cin >> n;   
	sum = 0;
	k = (1 << (n + 1)) - 1;
	for (int i = 2; i <= k; i++) {
		cin >> a[i];
	}
	
	sum = 0;
	
	for (int i = (1 << n) - 1; i >= 1; i--) {
		//cout << i << ' ' << a[i] << '\n';
		d = max(a[2 * i], a[2 * i + 1]);
		sum += d - min(a[2 * i], a[2 * i + 1]);
		a[i] += d;		
	}
	
	cout << sum;
	
	return 0;
}