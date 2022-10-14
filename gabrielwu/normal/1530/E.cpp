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
		string S;
		cin >> S;
		vector<int> cnt(26);
		for(char c: S){
			cnt[c - 'a']++;
		}
		int let = 0;
		int sing = -1;
		int a = -1;
		for(int i=25; i>=0; i--){
			if(cnt[i] == 1){
				sing = i;
			}
			if(cnt[i]){
				let++;
				a = i;
			}
		}
		string s = "";
		if(sing >= 0){
			s += (char)('a' + sing);
			forn(i, 26){
				if(i != sing){
					while(cnt[i]){
						cnt[i]--;
						s += (char)('a' + i);
					}
				}
			}
		}else{
			if(cnt[a] *2 - 2  <= S.size()){
				s+= (char) ('a' + a);
				s+= (char) ('a' + a);
				cnt[a]-=2;
				bool last = true;
				forn(times, S.size() - 2){
					forn(i, 26){
						if(cnt[i] && (i != a || !last)){
							s+= (char)('a' + i);
							cnt[i]--;
							break;
						}
					}
					last = !last;
				}
			}else{
				if(let >= 3){
					s+= (char) ('a' + a);
					cnt[a]--;
					int b = -1;
					forn(i, 26){
						if(cnt[i] && i != a){
							s+= (char)('a' + i);
							cnt[i]--;
							b = i;
							break;
						}
					}
					while(cnt[a]){
						cnt[a]--;
						s+= (char)('a' + a);
					}
					forn(i, 26){
						if(cnt[i] && i != b){
							s+= (char)('a' + i);
							cnt[i]--;
							break;
						}
					}
					forn(i, 26){
						while(cnt[i]){
							cnt[i]--;
							s+= (char)('a' + i);
						}
					}
				}else{
					s+= (char) ('a' + a);
					cnt[a]--;
					forn(i, 26){
						if(i != a){
							while(cnt[i]){
								cnt[i]--;
								s+= (char)('a' + i);
							}
						}
					}
					while(cnt[a]){
						cnt[a]--;
						s+= (char)('a' + a);
					}
				}
			}
		}
		cout << s << "\n";
	}
}