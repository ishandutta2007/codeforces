#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

////////////////////////////////////////////////////////////////////////
// Extended Euclidean Algorithm (UBC)
// egcd(a,b,x,y) calculates x,y such that ax+by=gcd(a,b)
// To find a^{-1} mod m, use egcd(a,m,x,y) and x = a^{-1}
// Returns gcd(a,b)
//*!
ll egcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        ll d = egcd(b, a%b, y, x);
        y -= x * (a/b);
        return d;
    }
}
//*/

////////////////////////////////////////////////////////////////////////
// Int struct for operations on a prime field (TESTED)
// WARNING: slow
//*!
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
//*/

////////////////////////////////////////////////////////////////////////
// Matrix Struct (UNTESTED)
// TESTED ON:
//   Multiplication
//     kattis: tritiling
//     cf: 222E
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
//*!
template <class T> struct Matrix {
    int rows, cols;
    vector<vector<T>> a;

    // EDIT THIS FOR NON-INTEGER TYPES
    bool iszero(const T& x) {
        return x == 0;
        //return abs(x) < EPS;  // for floating point T
    }

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
//*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	ll n;
	int m, k;
	cin >> n >> m >> k;

	Matrix<Int> ans(m,m,1);
	Matrix<Int> mat(m,m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = 1;
		}
	}

	char a, b;
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		if (islower(a)) x = a-'a';
		else x = a-'A' + 26;
		if (islower(b)) y = b-'a';
		else y = b-'A' + 26;
		mat[x][y] = 0;
	}

	--n;
	while (n > 0) {
		if (n & 1) ans *= mat;
		mat *= mat;
		n >>= 1;
	}

	vector<Int> sum = ans * vector<Int>(m,1);
	Int res;
	for (int i = 0; i < m; i++) {
		res += sum[i];
	}
	cout << res << nl;

	return 0;
}