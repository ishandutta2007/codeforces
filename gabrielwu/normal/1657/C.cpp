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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max

namespace Hashing {

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);
const array<int, 2> base = {BDIST(rng), BDIST(rng)};
vector<array<int, 2>> pows = {{1, 1}};

array<int, 2> operator + (array<int, 2> l, array<int, 2> r) {
    for (int i = 0; i < 2; i++)
        if ((l[i] += r[i]) >= MOD)
            l[i] -= MOD;
    return l;
}
array<int, 2> operator - (array<int, 2> l, array<int, 2> r) {
    for (int i = 0; i < 2; i++)
        if ((l[i] -= r[i]) < 0)
            l[i] += MOD;
    return l;
}
array<int, 2> operator * (array<int, 2> l, array<int, 2> r) {
    for (int i = 0; i < 2; i++)
        l[i] = (long long) l[i] * r[i] % MOD;
    return l;
}
array<int, 2> make_hash(char c) {
    return {c, c};
}
struct HashRange {
    //pre is rolling hash of form s[0]base^i + s[1]base^{i-1} + ... + s[i] mod MOD
    vector<array<int, 2>> pre = {{0, 0}};
    string s;
    void add(char c) {
        s += c;
        pre.push_back(base * pre.back() + make_hash(c));
    }
    void add(string t) {
        for (auto& c : t)
            add(c);
    }
    void extend(int len) {
        while ((int) pows.size() <= len)
            pows.push_back(base * pows.back());
    }
    array<int, 2> hash(int l, int r) {
        int len = r + 1 - l;
        extend(len);
        return pre[r + 1] - pows[len] * pre[l];
    }
};

} // Hashing

int main(){
	cin.tie(0)->sync_with_stdio(0);
	using namespace Hashing;

	int t;
	cin >> t;
	forn(ti, t) {
		HashRange fw, bw;
		int n;
		string s;
		cin >> n >> s;
		fw.add(s);
		string sback;
		for(int i=n-1; i>=0; i--) {
			sback += s.at(i);
		}
		bw.add(sback);

		int ops = 0;
		int check = 0;
		int curr = 0;
		bool pos = true;
		forn(i, n) {
			if(s.at(i) == '(') {
				curr++;
			} else {
				curr--;
				if(curr < 0) pos = false;
			}

			if((curr == 0 && pos) || (i > check && fw.hash(check, i) == bw.hash(n-1-i, n-1-check))) {
				ops++;
				check = i+1;
				curr = 0;
				pos = true;
			}
		}

		cout << ops << " " << (n - check) << "\n";

	}
	
}