#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 17;
const int MAXM = 50;

void pivot(int m,int n,ld a[MAXM][MAXN],
           int B[MAXM],int N[MAXN],int r,int c) {
  int i,j; swap(N[c], B[r]); a[r][c]=1/a[r][c];
  for(j=0;j<=n;j++) if(j!=c) a[r][j]*=a[r][c];
  for(i=0;i<=m;i++) if(i!=r) {
    for(j=0;j<=n;j++) if(j!=c) a[i][j]-=a[i][c]*a[r][j];
    a[i][c] = -a[i][c]*a[r][c]; } }
int feasible(int m,int n,ld a[MAXM][MAXN],int B[MAXM],int N[MAXN]) {
  int r,c,i; ld p,v;
  while(1) {
    for(p=INF,i=0; i<m; i++) if(a[i][n]<p) p=a[r=i][n];
    if(p>-EPS) return 1;
    for(p=0,i=0; i<n; i++) if(a[r][i]<p) p=a[r][c=i];
    if(p>-EPS) return 0;
    p = a[r][n]/a[r][c];
    for(i=r+1; i<m; i++) if(a[i][c]>EPS) {
      v = a[i][n]/a[i][c];
      if(v<p) r=i,p=v; }
    pivot(m,n,a,B,N,r,c); } }
int simplex(int m,int n,ld a[MAXM][MAXN],ld b[MAXN],ld& ret) {
  int B[MAXM],N[MAXN],r,c,i; ld p,v;
  for(i=0; i<n; i++) N[i]=i;
  for(i=0; i<m; i++) B[i]=n+i;
  if(!feasible(m,n,a,B,N)) return 0;
  while(1) {
    for(p=0,i=0; i<n; i++) if(a[m][i]>p) p=a[m][c=i];
    if(p<EPS) {
      for(i=0; i<n; i++) if(N[i]<n) b[N[i]]=0;
      for(i=0; i<m; i++) if(B[i]<n) b[B[i]]=a[i][n];
      ret = -a[m][n];
      return 1; }
    for(p=INF,i=0; i<m; i++) if(a[i][c]>EPS) {
      v = a[i][n]/a[i][c];
      if(v<p) p=v,r=i; }
    if(p==INF) return -1;
    pivot(m,n,a,B,N,r,c); }
}

ld mat[MAXM][MAXN];
ld vec[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int cap[2][3], d[7];
		for(int i=0; i<2; i++) {
			for(int j=0; j<3; j++) {
				cin >> cap[i][2-j];
			}
		}
		for(int i=0; i<7; i++) {
			cin >> d[i];
		}

		fill(&mat[0][0], &mat[0][0]+MAXM*MAXN, 0);
		int row = 0;
		for(int i=0; i<7; i++) {
			mat[row][2*i] = 1;
			mat[row][2*i+1] = 1;
			mat[row][14] = d[i];
			row++;
			mat[row][2*i] = -1;
			mat[row][2*i+1] = -1;
			mat[row][14] = -d[i];
			row++;
		}

		for(int i=0; i<2; i++) {
			for(int j=0; j<3; j++) {
				for(int bm=0; bm<7; bm++) {
					if(!(bm & 1<<j)) {
						mat[row][2*bm+i] = 1;
					}
				}
				mat[row][14] = cap[i][j];
				row++;
			}
		}

		for(int i=0; i<14; i++) {
			mat[row][i] = (i%2 == 0);
		}
		mat[row][14] = 0;

		ld maxv = 0;
		int ok = simplex(row, 14, mat, vec, maxv);
		if(!ok) {
			cout << -1 << nl;
			continue;
		}

		int out[14];
		for(int i=0; i<7; i++) {
			out[2*i] = floor(vec[2*i]);
			out[2*i+1] = d[i] - out[2*i];
			//cerr<<"got "<<vec[2*i]<<" -> "<<out[2*i]<<" and "<<out[2*i+1]<<nl;
			assert(0 <= out[2*i] && out[2*i] <= d[i]);
		}

		auto valid = [&]() {
			//cerr<<"try "; for(int i=0; i<7; i++) //cerr<<out[2*i]<<" ";
			//cerr<<nl;
			for(int i=0; i<7; i++) {
				if(out[2*i] < 0 || out[2*i] > d[i]) {
					return false;
				}
			}
			for(int i=0; i<2; i++) {
				for(int j=0; j<3; j++) {
					int sum = 0;
					for(int bm=0; bm<7; bm++) {
						if(!(bm & 1<<j)) {
							sum += out[2*bm+i];
						}
					}
					if(sum > cap[i][j]) {
						//cerr<<"false @ "<<i<<" "<<j<<nl;
						return false;
					}
				}
			}
			return true;
		};

		ok = false;
		for(int bm=0; bm<1<<7; bm++) {
			for(int i=0; i<7; i++) {
				if(bm & 1<<i) {
					out[2*i]++;
					out[2*i+1]--;
				}
			}
			if(valid()) {
				ok = true;
				break;
			}
			for(int i=0; i<7; i++) {
				if(bm & 1<<i) {
					out[2*i]--;
					out[2*i+1]++;
				}
			}
		}

		if(!ok) {
			cout << -1 << nl;
		} else {
			for(int i=0; i<7; i++) {
				cout << out[2*i] << " ";
			}
			cout << nl;
		}
	}

	return 0;
}