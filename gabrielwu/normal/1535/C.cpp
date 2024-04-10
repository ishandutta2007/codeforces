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

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		string s;
		cin >> s;
		int n = s.size();
		vector<int> v(n);
		forn(i, n){
			if(s.at(i) == '1'){
				if(i%2){
					v[i] = 1;
				}else{
					v[i] = 2;
				}
			}else if(s.at(i) == '0'){
				if(i%2){
					v[i] = 2;
				}else{
					v[i] = 1;
				}
			}
		}

		ll ans = 0;
		int left = 0, right = -1;
		int ones = 0, twos = 0;
		while(right+1 < n){
			right++;
			if(v[right] == 1) ones++;
			else if(v[right] == 2) twos++;
			while(ones > 0 && twos > 0){
				if(v[left] == 1) ones--;
				else if(v[left] == 2) twos--;
				left++;
			}
			ans += right - left + 1;
		}

		cout << ans << "\n";

	}
}