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

#define max_n 205


struct matrix {
  lint A[max_n][max_n];
	int n;

  matrix(int x = 0,int _n = 0) {
		n = _n;
    memset(A, 0, sizeof A);
		FOR(i,0,n) FOR(j,0,n) A[i][j] = -1;
		FOR(i,0,n) A[i][i] = 0;
	}

  friend matrix operator*(const matrix &a, const matrix &b) {
    matrix res(0,a.n);
    FOR(i,0,a.n) FOR(j,0,a.n) {
      lint best = -1;
      FOR(k,0,a.n) {
				if (a.A[i][k] != -1 && b.A[k][j] != -1) {
					best = max(best, a.A[i][k] + b.A[k][j]);
				}
      }
      res.A[i][j]=best;
    }
    return res;
  }

};



matrix power(matrix a, lint b) {
  matrix res(0,a.n);
	for (; b; b >>= 1LL, a = a * a)
    if (b & 1) res = res * a;
  return res;
}


set<string> prefy;
map<string, int> cena;
map<string, int> position;

int main() {
	IOS;
	int n; lint l;
	cin >> n >> l;
	VI edges;
	FOR(i,0,n) {
		int a; cin >> a; edges.pb(a);
	}
	vector<string> w;
	prefy.insert("");
	FOR(i,0,n) {
		string x; cin >> x; w.pb(x);
		cena[x] += edges[i];
		FOR(j,0,x.length()) {
			prefy.insert(x.substr(0,j+1));
		}
	}
	vector<string> graf;
	FORE(i,prefy) {
		graf.pb(*i);
		position[*i] = graf.size() - 1;
	}
	int N = prefy.size();
	matrix mat(0,N);
	FOR(i,0,N) FOR(j,0,N) mat.A[i][j] = -1;
	FOR(i,0,N) {
		FOR(let,0,26) {
			char C = let + 'a';
			string mys = graf[i] + C;
			int cost = 0;
			string przej = "";
			FOR(u,0,mys.length()) {
				if ( prefy.find(mys.substr(u))!=prefy.end()) {
					przej = mys.substr(u);
					break;
				}
			}
			int gdzie = position[przej];
			//debug3(graf[i], graf[gdzie], mys); 
			FOR(u,0,mys.length()) if (cena.find(mys.substr(u)) != cena.end()) cost += cena[mys.substr(u)];
			mat.A[i][gdzie] = cost;
		}
	}
	/*FOR(i,0,N) debug(graf[i]);
	FOR(i,0,N) FOR(j,0,N) {
		if (mat.A[i][j] != -1) {
			debug3(graf[i], graf[j], mat.A[i][j]);
		}
	}*/
	mat = power(mat, l);
	lint myns = 0;
	FOR(i,0,N) myns = max(myns, mat.A[0][i]);
	cout << myns << endl;
}