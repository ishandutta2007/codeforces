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

const int N = (1e5) + 100;

pair <int, pii> a[N];
int got[N], now = 1, done = 0;   
pii ans[N];          

int main(){ 
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	ll n, m;     
	cin >> n >> m;
	forn(i, n) got[i] = 1;
    forn(i, m){
    	cin >> a[i].fst >> a[i].snd.fst;
		a[i].snd.fst *= -1;
		a[i].snd.snd = i;
	}	           
	sort (a, a + m);   
	forn(i, m){
		if (a[i].snd.fst){
			done++;
			ans[a[i].snd.snd] = mp(1, done + 1);
		} else {         
			if (got[now] == now) {                   
				now++;	
			}                            
			if (done < now){
				puts("-1");
				return 0;
			}
	//		cerr << now << " " << got[now] << '\n';
			ans[a[i].snd.snd] = mp(got[now] + 1, now + 1);
			got[now]++;
		}
	}

	forn(i, m) cout << ans[i].fst << " " << ans[i].snd << '\n';
	return 0;
}