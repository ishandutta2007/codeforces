#include <bits/stdc++.h>                          

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef unsigned int uint;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int MAXN = int(3e2) + 10;

#define pii pair <int, int>
#define pll pair <ll, ll>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 
#define problem "test"

const int N = (2e5) + 100;        
            

int main(){ 
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	cout.precision(10);   
	int n, a[N], ra[N];
	cin >> n;  
	int ans = 0;
	forn(i, n){
		cin >> a[i];   
		ra[a[i] - 1] = i;    
	}    
	int i = 0;
	while (i != n){
		int cnt = i;
		while (i < n - 1 && ra[i + 1] > ra[i]) i++;
		ans = max(ans, i - cnt + 1);
		i++;              
	}
	cout << n - ans << '\n';   
}