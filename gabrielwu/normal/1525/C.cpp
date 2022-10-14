#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n, m;
		cin >> n >> m;
		vector<pii> e, o;
		forn(i, n){
			int x;
			cin >> x;
			if(x%2) o.pb(mp(x, i));
			else e.pb(mp(x, i));
		}

		sort(o.begin(), o.end());
		sort(e.begin(), e.end());

		vector<bool> dir(n);
		forn(i, n){
			char c;
			cin >> c;
			dir[i] = (c == 'R');
		}

		vector<int> ans(n, -1);
		stack<int> s;
		for(int i=0; i<o.size(); i++) {
			if(dir[o[i].s]) s.push(i);
			else{
				if(s.size()){
					int a = s.top(); s.pop();
					ans[o[i].s] = ans[o[a].s] = (o[i].f - o[a].f)/2;
				}
			}
		}
		vector<int> l, r;
		for(int i=0; i<o.size(); i++){
			if(ans[o[i].s] == -1){
				if(dir[o[i].s] == false){
					l.pb(i);
				} else r.pb(i);
			}
		}
		for(int i=0; i+1<l.size(); i+=2){
			ans[o[l[i]].s] = ans[o[l[i+1]].s] = (o[l[i]].f + o[l[i+1]].f)/2;
		}
		for(int i=r.size()%2; i+1<r.size(); i+=2){
			ans[o[r[i]].s] = ans[o[r[i+1]].s] = (2*m - o[r[i]].f - o[r[i+1]].f)/2;
		}

		if(l.size()%2 == 1 && r.size()%2 == 1){
			ans[o[l.back()].s] = ans[o[r[0]].s] = (2*m - o[r[0]].f + o[l.back()].f)/2;
		}


		s = stack<int>();
		for(int i=0; i<e.size(); i++) {
			if(dir[e[i].s]) s.push(i);
			else{
				if(s.size()){
					int a = s.top(); s.pop();
					ans[e[i].s] = ans[e[a].s] = (e[i].f - e[a].f)/2;
				}
			}
		}
		l = r = vector<int>();
		for(int i=0; i<e.size(); i++){
			if(ans[e[i].s] == -1){
				if(dir[e[i].s] == false){
					l.pb(i);
				} else r.pb(i);
			}
		}
		for(int i=0; i+1<l.size(); i+=2){
			ans[e[l[i]].s] = ans[e[l[i+1]].s] = (e[l[i]].f + e[l[i+1]].f)/2;
		}
		for(int i=r.size()%2; i+1<r.size(); i+=2){
			ans[e[r[i]].s] = ans[e[r[i+1]].s] = (2*m - e[r[i]].f - e[r[i+1]].f)/2;
		}

		if(l.size()%2 == 1 && r.size()%2 == 1){
			ans[e[l.back()].s] = ans[e[r[0]].s] = (2*m - e[r[0]].f + e[l.back()].f)/2;
		}

		forn(i, n) cout << ans[i] << " ";
		cout << "\n";

	}
}