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
#define LL long long int

using namespace std;

const int max_n = 2e5 + 5;

int n, x;
int t[max_n];
lint ans[max_n];

int fpw(int a, int b, int mod) {
	if (b == 0) return 1;
	int sq = fpw(a, b/2, mod);
	sq = (sq * 1LL * sq) % mod;
	if (b %2 == 0) return sq;
	return (sq * 1LL * a) % mod;
}

#define VL vector<long long>



struct fft_double {
  double PI = 3.141592653589793;
  using Complex = complex<double>;

  vector<Complex> dftn;
  vector<Complex> dfts;

  vector<Complex> pom;

  vector<Complex> a1;
  vector<Complex> a2;
  vector<Complex> b1;
  vector<Complex> b2;

  vector<double> cosi;
  vector<Complex> omega;

  fft_double() {}

  // @n to maksymalna suma rozmiarw mnoonych wielomianw.
  fft_double(int n, bool chce_dokladne) {
    n = potenga(n);
    dftn.resize(n + 1, 0);
    dfts.resize(n + 1, 0);
    pom.resize(n + 1, 0);
    if (chce_dokladne) {
      a1.resize(n + 1, 0);
      a2.resize(n + 1, 0);
      b1.resize(n + 1, 0);
      b2.resize(n + 1, 0);
    }
    cosi.resize(n + 1, 0);
    omega.resize(n + 1, 0);
  }

  inline int potenga(int v) {
    for (int i = 1; ; i *= 2) {
      if (i >= v) {
        return i;
      }
    }
    assert(false);
  }

  inline void dft(int n, int kier) {
    int n2 = n - 1;
    int s = 0;
    int p;
    int g;
    for (int i = 2; i <= n; i *= 2) {
      dftn.swap(dfts);
      p = n / i;
      if (kier) {
        g = 0;
        for (int j = 0; j < n; j++) {
          dftn[j] = dfts[(2 * (j - s) + s) & n2] +
                    omega[g] * dfts[(2 * (j - s) + p + s) & n2];
          s++;
          if (s == p) {
            g = j + 1;
            s = 0;
          }
        }
      } else {
        g = n;
        for (int j = 0; j < n; j++) {
          dftn[j] = dfts[(2 * (j - s) + s) & n2] +
                    omega[g] * dfts[(2 * (j - s) + p + s) & n2];
          s++;
          if (s == p) {
            g = n - j - 1;
            s = 0;
          }
        }
      }
    }
  }

  void licz_omegi(int n1) {
    double kat = 2.0 * PI / n1;
    int n2 = n1 - 1;
    int dod = 3 * n1 / 4;
    for (int i = 0; i <= n1; i++)
      cosi[i] = cos(kat * i);
    for (int i = 0; i <= n1; i++)
      omega[i] = Complex(cosi[i], cosi[(i + dod) & n2]);
  }

  vector<int> fft(vector<int> &jed, vector<int> &dwa) {
    int n1 = potenga(jed.size() + dwa.size());
    licz_omegi(n1);
    for (int i = 0; i < (int) jed.size(); i++)
      dftn[i] = jed[i];
    for (int i = (int) jed.size(); i < n1; i++)
      dftn[i] = 0;
    dft(n1, 1);
    for (int i = 0; i < n1; i++)
      pom[i] = dftn[i];
    for (int i = 0; i < (int) dwa.size(); i++)
      dftn[i] = dwa[i];
    for (int i = (int) dwa.size(); i < n1; i++)
      dftn[i] = 0;
    dft(n1, 1);
    for (int i = 0; i < n1; i++)
      dftn[i] *= pom[i];
    dft(n1, 0);
    vector<int> ret;
    for (int i = 0; i < n1; i++)
      ret.push_back(llround(dftn[i].real() / n1));
    return ret;
  }
};

fft_double fft(max_n, true);


void mnoz(VI& poly1, VI& poly2) {
	if (poly1.size() < 100 && poly2.size() < 100) {
		FOR(i,0,poly1.size()) FOR(j,0,poly2.size()) {
			if (i+j<=n) ans[i+j] += poly1[i] * 1LL * poly2[j];
		}
		return;
	}
	VI p[2];
	VI q[2];
	int hash = 1e4;
	FOR(i,0,poly1.size()) {
		p[0].pb(poly1[i]%hash);
		p[1].pb(poly1[i]/hash);
	}
	FOR(i,0,poly2.size()) {
		q[0].pb(poly2[i]%hash);
		q[1].pb(poly2[i]/hash);
	}
	FOR(i,0,2) FOR(j,0,2) { 
		bool samezera = true;
		FOR(u,0,p[i].size())  if (p[i][u] != 0) samezera = false;
		if (samezera) continue;
		samezera = true;
		FOR(u,0,q[j].size())  if (q[j][u] != 0) samezera = false;
		if (samezera) continue;

		VI x = fft.fft(p[i], q[j]);
		int domn = 1;
		if (i+j == 1) domn = hash;
		if (i+j == 2) domn = hash * hash;
		int zzz = x.size();
		FOR(u,0,min(n+1,zzz)) {
			ans[u] += x[u]*1LL*domn;
		}
	}
}


void rob(int a, int b) {
	if (b == a + 1) {
		if (t[a] == 0) ans[1]++;
		else ans[0]++;
	} else {
		int mid = (a + b) / 2;
		rob(a, mid);
		rob(mid, b);
		VI poly1; poly1.pb(0);
		int act = mid - 1;
		while (act >= a) {
			if (t[act] == 0) poly1.pb(1);
			else {
				poly1[poly1.size()-1]++;
			}
			act--;
		}
		VI poly2; poly2.pb(0);
		act = mid;
		while (act < b) {
			if (t[act] == 0) poly2.pb(1);
			else {
				poly2[poly2.size()-1]++;
			}
			act++;
		}
		mnoz(poly1, poly2);
	}
}



int main() {
	read2(n, x);
	
	FOR(i,0,n) {
		make(a);
		if ( a < x) t[i] = 0;
		else t[i] = 1;
	}
	rob(0,n);
	FOR(i,0,n+1) {
			printf("%lld ", ans[i]);
	}
	printf("\n");
}