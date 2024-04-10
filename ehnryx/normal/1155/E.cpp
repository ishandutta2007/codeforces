#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e6+3;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll egcd(ll a, ll b, ll& x, ll &y) {
  if (!b) {x = 1; y = 0; return a;}//to ensure d>=0: x=sgn(a);y=0;return abs(a);
  ll d = egcd(b, a%b, y, x); y -= x * (a/b); return d; }

////////////////////////////////////////////////////////////////////////
// Int struct for operations on a prime field (TESTED)
// WARNING: slow
struct Int {
    ll x;
    Int (ll n=0) { x = n % MOD; if (x < 0) x += MOD; }
    operator ll() { return x; }
    Int operator + (const Int& n) const { return Int(x + n.x); }
    Int operator - (const Int& n) const { return Int(x - n.x); }
    Int operator * (const Int& n) const { return Int(x * n.x); }
    Int operator / (const Int& n) const { return Int(x * n.inv()); }
    void operator += (const Int& n) { x = (x + n.x) % MOD; }
    void operator -= (const Int& n) { x = (x + MOD - n.x) % MOD; }
    void operator *= (const Int& n) { x = (x * n.x) % MOD; }
    void operator /= (const Int& n) { x = (x * n.inv()) % MOD; }
    ll inv() const {
        if (x == 0) throw runtime_error("divide by zero");
        ll c, d;
        egcd(x, MOD, c, d);
        return (c < 0) ? c+MOD : c;
    }
};

bool iszero(const Int& x) {
	return x.x == 0;
}


////////////////////////////////////////////////////////////////////////
// Matrix Struct (TESTED)
// TESTED ON:
//   Multiplication
//     kattis:tritiling, cf:222e
//   Row Reduction
//     kattis:primonimo, cf:100962a
//
// to declare an nxn diagonal matrix: Matrix<T> mat(n,n,d);
// to declare a rxc matrix: Matrix<T> mat(r,c);
// can construct a matrix with a vector<vector<T>>
//
// to solve a system of equations: Ax = b
// define Matrix<T> A;
// then x = A.solve(b, rank, pivot); (rank and pivot are optional)
// if no solution, x = empty vector
// free variables set to 0, and corresponding pivots set to -1
// EDIT the iszero function for non-integer T !!
template <class T> struct Matrix {
    int rows, cols;
    vector<vector<T>> a;

    // diagonal constructor
    Matrix(int r, int c, int v=0) {
        rows = r; cols = c;
        a.resize(r, vector<T>(c));
        if (v) for (int i = 0; i < min(r,c); i++)
            a[i][i] = v;
    }
    // 2d vector constructor
    Matrix(const vector<vector<T>>& v) {
        rows = v.size(); cols = v[0].size();
        a = v;
    }
    // access elements
    vector<T>& operator [] (unsigned int i) {
        return a[i];
    }

    // operations
    Matrix<T>& operator *= (const Matrix<T>& other) {
        return *this = *this * other;
    }
    Matrix<T> operator * (const Matrix<T>& other) {
        Matrix<T> res(rows,cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    res[i][j] += a[i][k] * other.a[k][j];
            }
        }
        return res;
    }
    vector<T> operator * (const vector<T>& v) {
        vector<T> res(rows);
        for (int i = 0; i < rows; i++) {
            res[i] = 0;
            for (int j = 0; j < cols; j++)
                res[i] += a[i][j] * v[j];
        }
        return res;
    }
    Matrix<T> operator + (const Matrix<T>& other) {
        Matrix<T> res(rows,cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res[i][j] = a[i][j] + other.a[i][j];
        return res;
    }
    Matrix<T>& operator += (const Matrix<T>& other) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                a[i][j] += other.a[i][j];
        return *this;
    }

    // solve system of equations, return empty if bad
    // pivot is -1 if free variable
    vector<T> solve(vector<T> goal, int& rank, vector<int>& pivot) {
        Matrix<T> rdu(a);           // reduced matrix
        rank = 0;                   // rank of matrix
        pivot.resize(cols, -1);     // row for pivot

        vector<int> order(rows);
        for (int i = 0; i < rows; i++) order[i] = i;

        for (int j = 0; j < cols; j++) {
            for (int i = rank; i < rows; i++) {
                if (!iszero(rdu[order[i]][j])) {
                    int piv = order[i];
                    swap(order[i], order[rank++]);
                    for (int r = rank; r < rows; r++) {
                        T factor = rdu[order[r]][j] / rdu[piv][j];
                        for (int k = j; k < cols; k++)
                            rdu[order[r]][k] -= factor * rdu[piv][k];
                        goal[order[r]] -= factor * goal[piv];
                    }
                    pivot[j] = piv;
                    break;
                }
            }
        }
        for (int i = rank; i < rows; i++) {
            if (!iszero(goal[order[i]])) return {};
        }

        vector<T> res(cols, 0);
        for (int j = cols-1; j >= 0; j--) {
            if (pivot[j] != -1) {
                res[j] = goal[pivot[j]];
                for (int k = j+1; k < cols; k++) {
                    res[j] -= rdu[pivot[j]][k] * res[k];
                }
                res[j] /= rdu[pivot[j]][j];
            }
        }
        return res;
    }

    vector<T> solve(vector<T> goal) {
        int rank;
        vector<int> pivot;
        return solve(goal, rank, pivot);
    }
};

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	const int k = 11;

	Matrix<Int> mat(k,k);
	vector<Int> vals;

	Int cur(1);
	For(i,k) {
		cout << "? " << i << endl;
		Int a(1);
		For(j,k) {
			mat[i][j] = a;
			a *= Int(i);
		}
		int v;
		cin >> v;
		assert(v != -1);
		vals.push_back(Int(v));
	}

	vector<Int> ans = mat.solve(vals);
	vector<Int> check = mat * ans;

	For(i,MOD) {
		Int res(0);
		for (int j=0; j<k; j++) {
			Int cur = Int(1);
			for (int t=0; t<j; t++) {
				cur *= Int(i);
			}
			res += ans[j]*cur;
		}
		if (res.x == 0) {
			cout << "! " << i << endl;
			return 0;
		}
	}

	cout << "! -1" << endl;

	return 0;
}