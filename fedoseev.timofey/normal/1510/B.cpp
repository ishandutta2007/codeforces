#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}

template<typename T>
class hungarian {
  public:
  int n;
  int m;
  vector< vector<T> > a;
  vector<T> u;
  vector<T> v;
  vector<int> pa;
  vector<int> pb;
  vector<int> way;
  vector<T> minv;
  vector<bool> used;
  T inf;
  hungarian(int _n, int _m) : n(_n), m(_m) {
    assert(n <= m);
    a = vector< vector<T> >(n, vector<T>(m));
    u = vector<T>(n + 1);
    v = vector<T>(m + 1);
    pa = vector<int>(n + 1, -1);
    pb = vector<int>(m + 1, -1);
    way = vector<int>(m, -1);
    minv = vector<T>(m);
    used = vector<bool>(m + 1);
    inf = numeric_limits<T>::max();
  }
  inline void add_row(int i) {
    fill(minv.begin(), minv.end(), inf);
    fill(used.begin(), used.end(), false);
    pb[m] = i;
    pa[i] = m;
    int j0 = m;
    do {
      used[j0] = true;
      int i0 = pb[j0];
      T delta = inf;
      int j1 = -1;
      for (int j = 0; j < m; j++) {
        if (!used[j]) {
          T cur = a[i0][j] - u[i0] - v[j];
          if (cur < minv[j]) {
            minv[j] = cur;
            way[j] = j0;
          }
          if (minv[j] < delta) {
            delta = minv[j];
            j1 = j;
          }
        }
      }
      for (int j = 0; j <= m; j++) {
        if (used[j]) {
          u[pb[j]] += delta;
          v[j] -= delta;
        } else {
          minv[j] -= delta;
        }
      }
      j0 = j1;
    } while (pb[j0] != -1);
    do {
      int j1 = way[j0];
      pb[j0] = pb[j1];
      pa[pb[j0]] = j0;
      j0 = j1;
    } while (j0 != m);
  }
  inline T current_score() {
    return -v[m];
  }
  inline T solve() {
    for (int i = 0; i < n; i++) {
      add_row(i);
    }
    return current_score();
  }
};

const int Inf = 1e5;

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int d, n;
    cin >> d >> n;
    vector <int> have(n);
    for (int i = 0; i < n; ++i) {
    	string s;
    	cin >> s;
    	reverse(s.begin(), s.end());
    	int mask = 0;
    	for (auto c : s) {
    		mask *= 2;
    		mask += c - '0';
    	}
    	//cout << "ms " << mask << endl;
    	have[i] = mask;
    }
    hungarian <int> h(n, n);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		if ((have[j] & have[i]) == have[i] && (i != j)) {
    			//cout << i << ' ' << j << endl;
    			h.a[i][j] = -(__builtin_popcount(have[i]) + 1);
    		} else {
    			h.a[i][j] = Inf;
    		}
    	}
    }
    h.solve();
    vector <int> nxt(n, -1), prv(n, -1);
    for (int i = 0; i < n; ++i) {
    	//cout << i << ' ' << h.pa[i] << endl;
    	if (h.pa[i] != -1 && h.a[i][h.pa[i]] != Inf) {
    		//cout << i << ' ' << h.pa[i] << endl;
    		nxt[i] = h.pa[i];
    		prv[h.pa[i]] = i;
    	}
    }
    //return 0;
	vector <vector <int>> ord;
	for (int i = 0; i < n; ++i) {
		if (prv[i] == -1) {
			//cout << "start " << i << endl;
			ord.push_back(vector <int> ());
			ord.back().push_back(0);
			int u = i;
			while (u != -1) {
				ord.back().push_back(have[u]);
				u = nxt[u];
			}
		}
	}
	/*for (auto v : ord) {
		for (auto x : v) {
			cout << x << ' ';
		}
		cout << endl;
	}*/
	vector <int> ans;
	for (int t = 0; t < (int)ord.size(); ++t) {
		if (t != 0) ans.push_back(-1);
		for (int i = 1; i < ord[t].size(); ++i) {
			int cm = ord[t][i] ^ ord[t][i - 1];
			//cout << cm << endl;
			for (int j = 0; j < d; ++j) {
				if (cm & (1 << j)) {
					ans.push_back(j);
				}
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans) {
		if (x != -1) {
			cout << x << ' ';
		} else {
			cout << "R ";
		}
	}
}