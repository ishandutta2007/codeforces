#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;
#define pb push_back
#define mp make_pair
#define MOD 998244353
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

typedef std::decay<decltype(MOD)>::type mod_t;
struct mi {
    mod_t val;
    explicit operator mod_t() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend std::istream& operator >> (std::istream& in, mi& a) {
        long long x; std::cin >> x; a = mi(x); return in; }
    friend std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val; }
    friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator != (const mi& a, const mi& b) { return !(a == b); }
    friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
    friend bool operator > (const mi& a, const mi& b) { return a.val > b.val; }
    friend bool operator <= (const mi& a, const mi& b) { return a.val <= b.val; }
    friend bool operator >= (const mi& a, const mi& b) { return a.val >= b.val; }
    mi operator - () const { return mi(-val); }
    mi& operator += (const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator -= (const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator /= (const mi& m) { return (*this) *= inv(m); }
    friend mi operator + (mi a, const mi& b) { return a += b; }
    friend mi operator - (mi a, const mi& b) { return a -= b; }
    friend mi operator * (mi a, const mi& b) { return a *= b; }
    friend mi operator / (mi a, const mi& b) { return a /= b; }
};


namespace MatrixOperations {

template <class T> using Matrix = std::vector<std::vector<T>>;

template <class T> Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r, std::vector<T>(c)); }

template <class T> Matrix<T>& operator += (Matrix<T>& a, const Matrix<T>& b) {
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[0].size(); j++) {
            a[i][j] += b[i][j];
        }
    }
    return a;
}

template <class T> Matrix<T>& operator -= (Matrix<T>& a, const Matrix<T>& b) {
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[0].size(); j++) {
            a[i][j] -= b[i][j];
        }
    }
    return a;
}

template <class T> Matrix<T> operator * (const Matrix<T>& a, const Matrix<T>& b) {
    assert(a[0].size() == b.size());
    int x = (int)a.size();
    int y = (int)a[0].size();
    int z = (int)b[0].size();
    Matrix<T> c = make_matrix<T>(x, z);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    return c;
}

template <class T> Matrix<T> operator + (Matrix<T> a, const Matrix<T>& b) { return a += b; }
template <class T> Matrix<T> operator - (Matrix<T> a, const Matrix<T>& b) { return a -= b; }
template <class T> Matrix<T>& operator *= (Matrix<T>& a, const Matrix<T>& b) { return a = a * b; }

template <class T> Matrix<T> pow(Matrix<T> m, long long p) {
    int n = (int)m.size();
    assert(n == (int)m[0].size() && p >= 0);
    Matrix<T> res = make_matrix<T>(n, n);
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    for (; p; p >>= 1, m *= m) {
        if (p & 1) {
            res *= m;
        }
    }
    return res;
}

template <class T> int get_row(Matrix<T>& m, int r, int i, int nxt) {
    for (int j = nxt; j < r; j++) {
        if (m[j][i] != 0) {
            return j;
        }
    }
    return -1;
}

const long double EPS = 1e-12;

template <> int get_row<long double>(Matrix<long double>& m, int r, int i, int nxt) {
    std::pair<long double, int> best = {0, -1};
    for (int j = nxt; j < r; j++) {
        best = std::max(best, {abs(m[j][i]), j});
    }
    return best.first < EPS ? -1 : best.second;
}

// returns a pair of determinant, rank, while doing Gaussian elimination to m
template <class T> std::pair<T, int> gauss(Matrix<T>& m) {
    int r = (int)m.size();
    int c = (int)m[0].size();
    int rank = 0, nxt = 0;
    T prod = 1;
    for (int i = 0; i < r; i++) {
        int row = get_row(m, r, i, nxt);
        if (row == -1) {
            prod = 0;
            continue;
        }
        if (row != nxt) {
            prod *= -1;
            m[row].swap(m[nxt]);
        }
        prod *= m[nxt][i];
        rank++;
        T x = 1 / m[nxt][i];
        for (int k = i; k < c; k++)
            m[nxt][k] *= x;
        for (int j = 0; j < r; j++) {
            if (j != nxt) {
                T v = m[j][i];
                if (v == 0) continue;
                for (int k = i; k < c; k++) {
                    m[j][k] -= v * m[nxt][k];
                }
            }
        }
        nxt++;
    }
    return {prod, rank};
}

template <class T> Matrix<T> inv(Matrix<T> m) {
    int r = (int)m.size();
    assert(r == (int)m[0].size());
    Matrix<T> x = make_matrix<T>(r, 2 * r);
    for (int i = 0; i < r; i++) {
        x[i][i + r] = 1;
        for (int j = 0; j < r; j++) {
            x[i][j] = m[i][j];
        }
    }
    if (gauss(x).second != r) return Matrix<T>();
    Matrix<T> res = make_matrix<T>(r, r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            res[i][j] = x[i][j + r];
        }
    }
    return res;
}

} // namespace MatrixOperations

int main(){
    fast_io();
    int n, m;
    cin >> n >> m;
    vi outdeg(n);
    vii inedge(n);
    vii outedge(n);
    forn(i, m){
      int u, v;
      cin >> u >> v;
      u--;v--;
      outdeg[u]++;
      inedge[v].pb(u);
      outedge[u].pb(v);
    }
    vi avail;
    forn(i, n){
      if(outdeg[i] == 0){
        avail.pb(i);
      }
    }
    vi g(n);
    forn(_, n){
      int x = avail.back(); avail.pop_back();
      for(int o: inedge[x]){
        outdeg[o]--;
        if(outdeg[o]==0){
          avail.pb(o);
        }
      }
      set<int> trans;
      for(int o: outedge[x]){
        trans.insert(g[o]);
      }
      while(trans.find(g[x]) != trans.end()){
        g[x]++;
      }
    }
    vi cnt(2*n);
    int maxg = 0;
    forn(i, n){
      cnt[g[i]]++;
      maxg = max(maxg, g[i]);
    }
    maxg = 1<<(32-__builtin_clz(maxg));
    vector<mi> p(maxg);
    forn(i, maxg){
      p[i] = mi(cnt[i])/mi(n+1);
    }
    using namespace MatrixOperations;

    using Mat = Matrix<mi>;
    Mat mat = make_matrix<mi>(maxg, maxg+1);
    forn(i, maxg){
      forn(j, maxg){
        mat[i][j] = p[i^j] - (i==j? 1: 0);
      }
    }
    mat[0][maxg] = -1/mi(n+1);

    // cout<< mat << "\n";
    gauss(mat);
    cout << 1-mat[0][maxg] << "\n";

    // cout << mat << "\n";
}