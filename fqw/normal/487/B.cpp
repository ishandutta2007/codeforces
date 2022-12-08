#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<double,double> PDD;
typedef pair<int,int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


template<class T> class FenwickTree {
	std::vector<T> a;
	int n; T v0;
public:
	FenwickTree() { }
	FenwickTree(int n, T v) : a(size_t(n+1), v), n(n), v0(v) { }
	void add(int x, T v) { for(; x<=n; x+=(x&-x)) a[(size_t)x]=min(a[(size_t)x], v); }
	T get(int x) const { T r=v0; for(; x>=1; x-=(x&-x)) r=min(r, a[(size_t)x]); return r; }
};
// ------------------------ template ends here ------------------------ //
const int MAXN=100010;
const int MAXLog=20;

int a[MAXN], n;
int s_min[MAXN][MAXLog];
int s_max[MAXN][MAXLog];

void make_st() {
	forint(i, 1, n)
		s_min[i][0]=s_max[i][0]=a[i];
	forint(j, 1, MAXLog-1)
		forint(i, 1, n) {
			s_min[i][j]=+(1<<29);
			s_max[i][j]=-(1<<29);
			if(i+(1<<j)-1<=n) {
				s_min[i][j]=min(s_min[i][j-1], s_min[i+(1<<j-1)][j-1]);
				s_max[i][j]=max(s_max[i][j-1], s_max[i+(1<<j-1)][j-1]);
			}
		}
}

int f[MAXN];

int main() {
	int s, l;
	scanf("%d%d%d",&n,&s,&l);
	forint(i, 1, n) scanf("%d", a+i);
	//cout<<"!"<<endl;
	make_st();
	//cout<<"!2"<<endl;

	int maxval=1<<30;
	FenwickTree<int> tr(n+1, maxval);

	f[n+1]=0;
	forintdown(i, n, 1) {
	//printf("i+%d\n",i);
		if(i+l<=n+1) tr.add(i+l, f[i+l]);
		f[i]=maxval;
		int j=i, v_min=a[i], v_max=a[i];
		forndown(k, MAXLog) {
			if(j+(1<<k)>n) continue;
			int d_min=min(v_min, s_min[j+1][k]);
			int d_max=max(v_max, s_max[j+1][k]);
			if(d_max-d_min<=s) {
				v_min=d_min; v_max=d_max;
				j+=(1<<k);
			}
		}
		if(i+l<=j+1)
			f[i]=tr.get(j+1)+1;
	}
	int ans=f[1]; if(ans>=maxval) ans=-1;
	printf("%d\n", ans);

	return 0;
}