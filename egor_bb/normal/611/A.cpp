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

                
int main(){ 
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout); 	
	int n;	
	string s, t;
	cin >> n >> t >> s;
	if (s[0] == 'w'){
		if (n == 5 || n == 6) cout << 53 << '\n';
		else cout << 52 << '\n';
	}   else {
		if (n == 31) cout << 7;
		else if (n == 30) cout << 11;
		else cout << 12;
	}

}