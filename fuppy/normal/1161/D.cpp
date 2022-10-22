#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}


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
const ll INF = (ll)1e18 + 1;
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

class UnionFind {
public:
	int n;
	vi par; //
	vi ran; //
	vi num; //

	UnionFind(int _n) {
		n = _n;
		par.resize(n); ran.resize(n); num.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i; ran[i] = 0; num[i] = 1;
		}
	}

	//
	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}

	//xy
	void unite(int x, int y) {
		x = find(x); y = find(y);
		int numsum = num[x] + num[y];
		if (x == y) {
			return;
		}
		if (ran[x]<ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y]) {
				ran[x]++;
			}
		}
		num[x] = num[y] = numsum;
	}

	//xy
	bool same(int x, int y) {
		return find(x) == find(y);
	}

};


int main() {
  string s;
  cin >> s;
  if (s.back() == '1') {
    cout << 0 << endl;
    return 0;
  }
  else {
    s.back() = '0';
  }
  int n = s.size();

  ll ans = 0;
  for (int i = n - 1; i > 0; i--) {
    //DEBUG(i);
    UnionFind uf(2*n);
    for (int u = 0; u < n; u++) {
      int v = n - 1 - u;
      if (u >= v)  break;
      uf.unite(u, v);
    }

    for (int u = i; u < n; u++) {
      int v = n - 1 - (u - i);
      uf.unite(u + n, v + n);
    }

    for (int u = 0; u < i; u++) {
      uf.unite(n, n + u);
    }

    rep (j, n) {
      if (s[j] == '0') {
        uf.unite(j, j + n);
      }
    }

    vector<set<int> > mujun(2*n);
    bool flag = true;
    rep (j, n) {
      if (s[j] == '1') {
        if (uf.same(j, j + n)) {
          flag = false;
          break;
        }
        mujun[uf.find(j)].insert(uf.find(j + n));
        mujun[uf.find(j + n)].insert(uf.find(j));
      }
    }

    if (!flag) {
      continue;
    }

    rep (j, 2*n) {
      if (mujun[j].size() <= 1) continue;
      auto itr = mujun[j].begin();
      int u = *itr;
      itr++;
      for (; itr != mujun[j].end(); itr++) {
        int v = *itr;
        uf.unite(u, v);
      }
      mujun[j].clear();
    }

    rep (j, n) {
      if (s[j] == '1') {
        if (uf.same(j, j + n)) {
          flag = false;
          break;
        }
        mujun[uf.find(j)].insert(uf.find(j + n));
        mujun[uf.find(j + n)].insert(uf.find(j));
      }
    }

    /*
    rep (j, n) cout << uf.find(j);
    cout << endl;
    rep (j, n) cout << uf.find(n + j);
    cout << endl;
    //*/

    set<int> root;
    rep (j, 2*n) root.insert(uf.find(j));

    vi color(2*n, -1);
    if (uf.same(0, n)) {
      continue;
    }

    ll res = 1;
    int nokori = 2*n;
    color[uf.find(0)] = 1;
    color[uf.find(n)] = 0;
    queue<pii> qu;
    qu.push(pii(uf.find(0), 1));
    qu.push(pii(uf.find(n), 0));
    nokori -= uf.num[uf.find(0)];
    nokori -= uf.num[uf.find(n)];
    root.erase(uf.find(0));
    root.erase(uf.find(n));
    
    flag = true;
    while (flag && nokori > 0) {
      if (qu.empty()) {
        int u = *root.begin();
        u = uf.find(u);
        color[u] = 1;
        res = res * 2 % MOD;
        //DEBUG(u);
        qu.push(pii(u, 1));
        nokori -= uf.num[u];
        root.erase(root.begin());
      }
      while (!qu.empty()) {
        int u = qu.front().first, c = qu.front().second;
        qu.pop();
        for (auto itr = mujun[u].begin(); itr != mujun[u].end(); itr++) {
          int v = *itr;
          v = uf.find(v);
          if (color[v] != -1) {
            if (color[v] == c) {
              res = 0;
              flag = false;
              queue<pii> emp;
              swap(qu, emp);
              break;
            }
            else continue;
          }
          else {
            color[v] = 1 - c;
            qu.push(pii(v, color[v]));
            nokori -= uf.num[v];
            root.erase(v);
          }
        }
      }
    }

    if (!flag) continue;

    rep (j, n) {
      if (s[j] == '0') {
        if (color[uf.find(j)] != color[uf.find(j + n)]) {
          flag = false;
          break;
        }
      }
      if (s[j] == '1') {
        if (color[uf.find(j)] == color[uf.find(j + n)]) {
          flag = false;
          break;
        }
      }
    }
    
    if (!flag) continue;
    //DEBUG(res);
    ans = (ans + res) % MOD;
    //DEBUG(ans);
  }
  cout << ans << endl;
}