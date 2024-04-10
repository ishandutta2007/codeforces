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
		string s;
		cin >> s;
		vector<bool> seen(26);
		vector<int> cnt(26);
		vector<int> ord;
		for(int i = s.size() - 1; i>=0; i--){
			cnt[s.at(i) - 'a']++;
			if(!seen[s.at(i) - 'a']){
				seen[s.at(i) - 'a'] = true;
				ord.pb(s.at(i) - 'a');
			}
		}

		bool works = true;
		vector<int> rc(26);
		forn(i, ord.size()){
			if(cnt[ord[i]] % (ord.size() - i) > 0){
				works = false;
			} else {
				rc[ord[i]] = cnt[ord[i]] / (ord.size() - i);
			}
		}

		if(works == false){
			cout << -1 << "\n";
			continue;
		}

		string t;
		int left = ord.size();
		for(char c: s){
			t += c;
			rc[c - 'a'] --;
			if(rc[c-'a'] < 0){
				works = false;
				break;
			} else if(rc[c-'a'] == 0){
				left--;
			}

			if(left == 0) break;
		}

		if(works == false){
			cout << -1 << "\n";
			continue;
		}

		string news;
		reverse(ord.begin(), ord.end());
		vector<bool> active(26, true);
		forn(times, ord.size()){
			for(char c: t){
				if(active[c - 'a']) news += c;
			}
			active[ord[times]] = false;
		}

		if(news == s){
			cout << t << " ";
			for(int x: ord){
				cout << (char) (x + 'a');
			}
			cout << "\n";
		}else{
			cout << -1 << "\n";
		}
	}
}