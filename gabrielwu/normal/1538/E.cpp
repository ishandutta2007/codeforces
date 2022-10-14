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
ll count(string s){
	int ans = 0;
	for(int i=0; i+4<=s.size(); i++){
		ans += (s.substr(i, 4) == "haha");
	}
	return ans;
}

struct Str {
	string left, right;
	ll cnt;

	Str() {}

	Str(string s): left(s), right(s), cnt(0){
		if(s.size() == 4){
			cnt = (s == "haha");
		} else if(s.size() == 5){
			cnt = (s.substr(0, 4) == "haha" || s.substr(1, 4) == "haha");
		}
	}

	Str(string l, string r, ll c): left(l), right(r), cnt(c) {}

	Str comb(Str oth){
		string nl = left + oth.left, nr = right + oth.right;
		nl = nl.substr(0, min((int)nl.size(), 5));
		nr = nr.substr((int)nr.size() - min((int)nr.size(), 5), min((int)nr.size(), 5));
		ll nc = cnt + oth.cnt;
		string mid = right + oth.left;
		nc += count(mid) - count(right) - count(oth.left);

		return Str(nl, nr, nc);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;
		map<string, Str> dict;

		forn(i, n){
			string a, b;
			cin >> a >> b;
			if(b == ":="){
				string c;
				cin >> c;
				dict[a] = Str(c);
			} else {
				string c, d, e;
				cin >> c >> d >> e;
				assert(d == "+");
				dict[a] = dict[c].comb(dict[e]);
			}

			if(i == n-1){
				cout << dict[a].cnt << "\n";
			}
		}
	}
}