#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
typedef double T; // long double , Rational , double + mod < P>...
typedef vector<T> vd;
typedef vector<vd> vvd;
const T eps = 1e-8, inf = 1/.0;
#define MP make_pair
#define ltj(X) if(s == -1 || MP(X[j],N[j]) < MP(X[s],N[s])) s=j
struct LPSolver {
	int m, n;
	vi N, B;
	vvd D;
	LPSolver(const vvd& A, const vd& b, const vd& c) :
	m(sz(b)), n(sz(c)), N(n+1), B(m), D(m+2, vd(n+2)) {
		rep(i,0,m) rep(j,0,n) D[i][j] = A[i][j];
		rep(i,0,m) { B[i] = n+i; D[i][n] = -1; D[i][n+1] = b[i];}
		rep(j,0,n) { N[j] = j; D[m][j] = -c[j]; }
		N[n] = -1; D[m+1][n] = 1;
	}
	void pivot(int r, int s) {
		T *a = D[r].data(), inv = 1 / a[s];
		rep(i,0,m+2) if (i != r && abs(D[i][s]) > eps) {
			T *b = D[i].data(), inv2 = b[s] * inv;
			rep(j,0,n+2) b[j] -= a[j] * inv2;
			b[s] = a[s] * inv2;
		}
		rep(j,0,n+2) if (j != s) D[r][j] *= inv;
		rep(i,0,m+2) if (i != r) D[i][s] *= -inv;
		D[r][s] = inv;
		swap(B[r], N[s]);
	}
	bool simplex(int phase) {
			int x = m + phase - 1;
			for (;;) {
				int s = -1;
				rep(j,0,n+1) if (N[j] != -phase) ltj(D[x]);
				if (D[x][s] >= -eps) return true;
				int r = -1;
				rep(i,0,m) {
					if (D[i][s] <= eps) continue;
					if (r == -1 || MP(D[i][n+1] / D[i][s], B[i])
						< MP(D[r][n+1] / D[r][s], B[r])) r = i;
				}
			if (r == -1) return false;
			pivot(r, s);
		}
	}
	T solve(vd &x) {
		int r = 0;
		rep(i,1,m) if (D[i][n+1] < D[r][n+1]) r = i;
		if (D[r][n+1] < -eps) {
			pivot(r, n);
			if (!simplex(2) || D[m+1][n+1] < -eps) return -inf;
			rep(i,0,m) if (B[i] == -1) {
				int s = 0;
				rep(j,1,n+1) ltj(D[i]);
				pivot(i, s);
			}
		}
		bool ok = simplex(1); x = vd(n);
		rep(i,0,m) if (B[i] < n) x[B[i]] = D[i][n+1];
		return ok ? D[m][n+1] : inf;
	}
};
void solve()
{
	int n,p,q;
	cin>>n>>p>>q;
	vd C,D,optimalx;
	vvd A(2,vd(n));
	rep(i,0,n){
		cin>>A[0][i]>>A[1][i];
		A[0][i]*=-1;
		A[1][i]*=-1;	
	}
	D.pb(-p);
	D.pb(-q);
	rep(i,0,n)
		C.pb(-1);
	T ans=LPSolver(A,D,C).solve(optimalx);
	cout<<fixed<<setprecision(6)<<-ans;
}
// min sum x[i]
// sum a[i]*x[i] >= p
// sum b[i]*x[i] >= q

// max py1+qy2
// 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}