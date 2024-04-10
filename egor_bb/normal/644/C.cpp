#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()
                  
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 1e5 + 10;
const int INF = 2e9;

string s;
vector <string> name;
vector < vector <string> > v;
map <string, int> m;
map <vector <string>, vector <int> > m2;

int main(){    
	ios_base::sync_with_stdio(0);
	cin.tie(0);                                                  
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout); 
	int n;
	cin >> n;
	v.resize(n);
	int got = 0;
	forn(q, n) {
		cin >> s;
		int cnt = 0;
		int len = sz(s);
		int i = 0;
		while (i < len) {
			if (s[i] == '/')
				cnt++;
			if (cnt == 3)
				break;
			++i;
		}
		string t = "";
		forab(j, i, len)
			t.pb(s[j]);
		s.erase(s.begin() + i, s.end());
		int now = -1;
		if (!m[s]) {
			got++;
			m[s] = got;
			now = got - 1;
			name.pb(s);
		} else {
			now = m[s] - 1;
		}
		v[now].pb(t);
	}
	forn(i, got) {
		sort(all(v[i]));
		v[i].resize(unique(all(v[i])) - v[i].begin());
		m2[v[i]].pb(i);
	}
	int k = 0;
	for (auto it : m2) {
		
		if (sz(it.second) > 1) ++k;
	}
	cout << k << '\n';
	for (auto it : m2) {
		if (sz(it.second) > 1) {
			forn(i, sz(it.second)) {
				cout << name[it.second[i]] << " ";
			}
			cout << '\n';
		}
	}
	return 0 ;	
}