#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));

using namespace std;
#define max_n 40

int mod = 1e9+7;

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

void dbg(matrix m){
	cerr<<"macierz"<<"="<<endl;
	FOR(i,0,m.n){
		FOR(j,0,m.n){
			cerr<<m.A[i][j]<<" ";
		}
		cerr<<endl;
	}
}


matrix ch[100][50];
matrix pref[50],suf[50];


int main(){
	lint n; int k;
	cin>>n>>k;
	n--;
	VI digits;
	int l = 0;
	while(n>0){
		digits.pb(n%k);
		n = n/k;
		l++;
	}
	
	FOR(i,0,k){
		ch[0][i] = matrix(1,k+1);
		FOR(j,0,k+1) ch[0][i].A[i][j] = 1;
	}


	FOR(i,1,l+1){
		pref[0] = ch[i-1][0];
		FOR(j,1,k) pref[j] = ch[i-1][j]*pref[j-1];

		suf[k-1] = ch[i-1][k-1];
	
		FORD(j,k-2,0){
			suf[j] = suf[j+1]*ch[i-1][j];
		}
		
		ch[i][0] = suf[0];

		FOR(j,1,k){
			ch[i][j] = pref[j-1]*suf[j];
		}
	}


	matrix m = matrix(1,k+1);
	int reszta = 0;
	FORD(i,l-1,0){
		FOR(j,0,digits[i]){
			m = ch[i][(reszta+j)%k]*m;
		}
		reszta = (reszta+digits[i])%k;
	}
	m = ch[0][reszta]*m;
	VI w; FOR(i,0,k) w.pb(0); w.pb(1);
	
	w = m * w;
	lint ans = 0;
	FOR(i,0,w.size()) ans = (ans+w[i])%mod;
	cout<<ans<<endl;


	return 0;
}