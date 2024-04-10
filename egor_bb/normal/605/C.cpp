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
                                                
pll a[N];          

bool cmp (pii a, pii b){
	return (1ll * a.snd * b.fst < 1ll * a.fst * b.snd);
}


bool cw (pii a, pii b, pii c) {
	return a.fst*1ll*(b.snd-c.snd)+b.fst*1ll*(c.snd-a.snd)+c.fst*1ll*(a.snd-b.snd) > 0;
}

ll det (ll a, ll b, ll c, ll d) {
	return a * d - b * c;
}

struct line{
	ll a, b, c;
};

pair <double, double> res;
 
bool intersect (line m, line n, pair <double, double> &res) {
	ll zn = det (m.a, m.b, n.a, n.b);
	res.fst = - det (m.c, m.b, n.c, n.b) *1. / zn;
	res.snd = - det (m.a, m.c, n.a, n.c) *1. / zn;
	return true;
}


int main(){ 
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	cout.precision(10);
	ll n, p, q;  
	cin >> n >> p >> q;   
	double ans = 1e18;                     
	forn(i, n){
		cin >> a[i].fst >> a[i].snd;
		ans = min(ans, max(p * 1. / a[i].fst, q * 1. / a[i].snd));
	} 
	sort (a, a + n, &cmp);
//	forn(i, n) cout << a[i].fst << " "<<  a[i].snd << '\n';
	
	vector <pii> s;
	s.pb(mp(0, 0));
	s.pb(a[0]);
	for (int i = 1; i < n; i++){
		while (s.size()>=2 && !cw (s[s.size()-2], s[s.size()-1], a[i])) {
			s.pop_back();
//			cerr << "!";
		}
		s.push_back (a[i]); 
	}                           
//	forn(i, sz(s))		 cout << s[i].fst << " "<<  s[i].snd << '\n';
	int i = sz(s) - 1;
	while (i > 0 && cw(mp(p, q), s[i], mp(0, 0))) i--;
//	cout << i << '\n';
	pii p1, p2;
	if (!i || i == sz(s) - 1){
		if (!i) p1 = s[1];
		else p1 = s[i];                                 
		cout << fixed << ans << '\n';
		return 0;
	}                          
	p1 = s[i];
	p2 = s[i + 1];
	line x1;
	x1.a = p1.snd - p2.snd;
	x1.b = p2.fst - p1.fst;
	x1.c = -x1.a*p1.fst -x1.b * p1.snd;
	line x2;
	x2.c = 0;
	x2.a = q;
	x2.b = -p;
	intersect(x1, x2, res);	
	ans = min(ans, sqrt((p * 1. * p + q * 1. * q) / (res.fst * res.fst + res.snd * res.snd)));
	cout << fixed << ans << '\n'; 
	return 0;
}