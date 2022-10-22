#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


class Bit {
public:
	int n;
	vl bit; // 0-index

	Bit(int _n) { n = _n; bit.resize(n); }

	// [0, i)
	ll sum(int i) {
		ll s = 0;
		while (i > 0) {
			s += bit[i - 1];
			i -= i & -i;
		}
		return s;
	}

	//i0-index
	void add(int i, ll x) {
		i++;
		while (i <= n) {
			bit[i - 1] += x;
			i += i & -i;
		}
	}

	// bitx
	// 1x = 1;
	// bit3add(3, 1), 3add(3, -1)
	// return == nx
	ll min_xth(int x) {
		int left = -1, right = n;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			int temp = sum(mid + 1);
			if (temp < x) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return right;
	}


	// p
	ll bubble(vi p) {
		int n = p.size();
		ll ans = 0;
		for (int j = 0; j < n; j++) {
          (ans += (j - sum(p[j] + 1))) %= MOD;
          add(p[j], 1);
		}
		return ans % MOD;
	}
};

const int MAXN = 200010;

vl fact(MAXN);
vl rfact(MAXN);

ll mod_pow(ll x, ll p, ll M = MOD) {
	ll a = 1;
	while (p) {
		if (p % 2)
			a = a*x%M;
		x = x*x%M;
		p /= 2;
	}
	return a;
}

ll mod_inverse(ll a, ll M = MOD) {
	return mod_pow(a, M - 2, M);
}

void set_fact(ll n, ll M = MOD) {
	fact[0] = fact[1] = rfact[0] = rfact[1] = 1;
	for (ll i = 2; i <= n; i++) {
		fact[i] = i * fact[i - 1] % M;
		rfact[i] = mod_inverse(fact[i], M);
	}
}

ll nCr(ll n, ll r, ll M = MOD) {
  if (r > n) return 0;
  ll ret = fact[n];
  ret = (ret*rfact[r]) % M;
  ret = (ret*rfact[n - r]) % M;
  return ret;
}


int main() {
  fio();
  int n;
  cin >> n;
  set_fact(n + 5);
  vi p(n);
  int m = 0;
  set<int> st;
  rep (i, n) {
    cin >> p[i];
    if (p[i] == -1) m++;
    else {
      p[i]--;
      st.insert(p[i]);
    }
  }
  int k = n - m;
  int cnt = 0;
  map<int, int> mp;
  for (auto itr = st.begin(); itr != st.end(); itr++) {
    mp[*itr] = cnt++;
  }
  vi p2;
  rep (i, n) {
    if (p[i] == -1) continue;
    p2.push_back(mp[p[i]]);
  }
  Bit bit(k);
  ll ans1 = bit.bubble(p2);
  ll ans3 = (nCr(m, 2) * mod_inverse(2)) % MOD;
  vl num(n);
  rep (i, n) {
    if (!st.count(i)) {
      num[i]++;
    }
  }
  vl sum(n);
  sum[0] = num[0];
  rep (i, n - 1) {
    sum[i + 1] = sum[i] + num[i + 1];
  }
  //DEBUG_VEC(sum);
  ll ml = 0, mr = m;
  ll ans2 = 0;
  rep (i, n) {
    if (p[i] == -1) {
      ml++;
      mr--;
    }
    else {
      ll xl = sum[p[i]];
      ll xr = m - xl;
      (ans2 += (xl * mr % MOD * mod_inverse(m) % MOD + xr * ml % MOD * mod_inverse(m) % MOD)) %= MOD;
    }
  }
  ll ans = (ans1 + ans2 + ans3) % MOD;
  cout << ans << endl;
}