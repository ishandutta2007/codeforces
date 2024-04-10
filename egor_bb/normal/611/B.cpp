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
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 
#define problem "test"
                            
      
const int N = (5e2) + 100;
const int magic = 1000;


int n, m;
string s[N];
ll dp[N][N];

int main(){ 
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout); 	
	vector <ll> ans;
	forab(i, 2, 63){
		forn(j, i - 1){
			ll pow = 1;
			ll num = 0;
			forn(k, i){
				if (k != j) num += pow;
				pow *= 2;
			}	
			ans.pb(num);
		}	
	}	
	sort(all(ans));
	ll a, b;
	cin >> a >> b;
	cout << upper_bound(all(ans), b) - lower_bound(all(ans), a) << '\n';

}