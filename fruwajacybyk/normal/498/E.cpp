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
#define max_n 200

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



matrix power(matrix a, int b) {
  matrix res(1,a.n);
  for (; b; b >>= 1, a = a * a)
    if (b & 1) res = res * a;
  return res;
}


int dp[200][200][10][3];

int ile(int m1,int m2, int l, int jest){
	if(l==1){
		if(m1==1 && m2==1 && jest==1) return 0;
		else return 1;
	}
	if(dp[m1][m2][l][jest]!=-1) return dp[m1][m2][l][jest];
	int x1 = m1%2, x2 = m2%2; 
	dp[m1][m2][l][jest] = ile(m1/2,m2/2,l-1,0);
	if(x1!=1 || x2!=1 || jest!=1){
		dp[m1][m2][l][jest] += ile(m1/2,m2/2,l-1,1);
		dp[m1][m2][l][jest]%=mod;
	}
	return dp[m1][m2][l][jest];
}

matrix t[10];

int main(){
	FOR(i,0,1<<7) FOR(j,0,1<<7) FOR(k,0,9) FOR(l,0,3) dp[i][j][k][l] = -1;
	FOR(k,0,7){
		FOR(i,0,1<<(k+1)) FOR(j,0,1<<(k+1))
			FOR(l,0,2)
				dp[i][j][k+1][l] = ile(i,j,k+1,l);
	}
	VI v; v.pb(0); v.pb(1);

	FOR(i,1,8){
		FOR(j,0,1<<i) FOR(k,0,1<<i) {
			t[i].n = (1<<i);
			t[i].A[j][k] = dp[j][k][i][1];
		}
	}

	FOR(i,1,8){
		make(w);
		VI v2 = power(t[i],w)*v;
		FOR(k,0,(1<<i)) v[k] = 0;
		FOR(k,0,(1<<i)) v.pb(v2[k]);
	}

	printf("%d\n",v.back());

	

	return 0;
}