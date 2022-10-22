#include "bits/stdc++.h"

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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);i++)
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(ll)(n);i>0;i--)
#define REP(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
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
  fio();
  int n;
  cin >> n;
  vector<vii> G(4, vii(4));
  rep (i, n) {
    int u, x, v;
    cin >> u >> x >> v;
    u--; v--;
    if (u > v) {
      swap(u, v);
    }
    G[u][v].push_back(x);
  }
  vi num(4);
  vi sum(4);
  rep (i, 4) {
    REP (j, i, 4) {
      num[i] += G[i][j].size();
      num[j] += G[i][j].size();
      rep (k, G[i][j].size()) {
        sum[i] += G[i][j][k];
      }
    }
  }
  rep (i, 4) {
    REP (j, i, 4) {
      sort(all(G[i][j]));
    }
  }
  //DEBUG_VEC(num);
  //DEBUG_VEC(sum);
  int ans = 0;
  rep (mask, 1 << 16) {
    vi num2 = num;
    vi sum2 = sum;
    bool flag = true;
    UnionFind uf(4);
    rep (i, 4) {
      REP (j, i, 4) {
        int k = i * 4 + j;
        if (mask & (1 << k)) {
          if (G[i][j].size() >= 2) {
            uf.unite(i, j);
          }
        }
        else {
          if (G[i][j].size() >= 1) {
            uf.unite(i, j);
          }
        }
        if ((mask & (1 << k))) {
          if (G[i][j].size() == 0) {
            flag = false;
            i = j = 100;
            break;
          }
          num2[i]--;
          num2[j]--;
          sum2[i] -= G[i][j][0];
        }
      }
    }
    if (!flag) {
      continue;
    }
    //DEBUG(mask);
    //DEBUG_VEC(num2);
    rep (i, 4) {
      int gu = 0, ki = 0;
      int temp = 0;
      rep (j, 4) {
        if (uf.find(j) == i) {
          temp += sum2[j];
          if (num2[j] % 2 == 0) {
            gu++;
          }
          else {
            ki++;
          }
        }
      }
      if (ki == 0 || ki == 2) {
        chmax(ans, temp);
      }
    }
  }
  cout << ans << endl;
}