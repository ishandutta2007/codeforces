#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}


using namespace std;

#define max_n 2

int mod = 1e9+7;
int half = (mod+1)/2;

struct matrix {
  int A[max_n][max_n];
	int n;

  matrix(int x = 0,int _n = 0) {
		n = _n;
    memset(A, 0, sizeof A);
    FOR(i,0,n) A[i][i] = x;
  }

  friend matrix operator*(const matrix &a, const matrix &b) {
    lint mod2 = mod*1LL*mod;
    matrix res(0,a.n);
    FOR(i,0,a.n) FOR(j,0,a.n) {
      lint act = 0;
      FOR(k,0,a.n) {
        act+=a.A[i][k]*1LL*b.A[k][j];
        if(act>=mod2) act-=mod2;
      }
      res.A[i][j]=act%mod;
    }
    return res;
  }

	friend VI operator*(const matrix &a, const VI & v){
		VI res;
		FOR(i,0,a.n){
			lint act = 0;
			FOR(k,0,a.n){
				act+= a.A[i][k] * 1LL * v[k];
				act%= mod;
			}
			res.pb(act);
		}
		return res;
	}
};



matrix power(matrix a, lint b) {
  matrix res(1,2);
  for (; b; b >>= 1LL, a = a * a)
    if (b & 1) res = res * a;
  return res;
}

int powmod(int a, lint b) {
	if (b==0) return 1;
	int sq = powmod(a,b/2);
	sq = (sq * 1LL * sq) % mod;
	if (b%2==0) return sq;
	return (sq * 1LL * a)%mod;
}

int main() {
	IOS;
	int k;
	cin >> k;
	matrix mat(0,2);
	mat.A[0][0] = 0;
	mat.A[0][1] = 1;
	mat.A[1][0] = mat.A[1][1] = half;
	int mian = 2;
	FOR(i,0,k) {
		lint x; 
		cin >> x;
		mat = power(mat, x);
		mian = powmod(mian, x);
	}
	mian = (mian * 1LL * half) % mod;
	int licz = (mat.A[0][0]*1LL*mian)%mod;
	printf("%d/%d\n", licz, mian);
}