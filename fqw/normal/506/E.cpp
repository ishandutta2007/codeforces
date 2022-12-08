// 11:03
// 11:43 -> WA sample
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
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


// ------------------------ template ends here ------------------------ //
const int MAXS=206;
const int MAXN=MAXS*2;
const int MOD=10007;

inline void add(int &a, int b) {
	a+=b; if(a>=MOD) a-=MOD;
}

struct N_struct {
	// N[n25, b]: num of paths passing [n25] 25-nodes
	//    b=0: normal
	//    b=1: match two on last step
	int a[MAXS][2];
};

void compute_N(N_struct &N, string s) {
	fillchar(N.a, 0);
	static int h[MAXS][MAXS][MAXS][2];
	fillchar(h, 0);
	h[0][0][0][0]=1;
	int sn=(int)s.size();
	forint(i, 0, sn) forint(j, 0, sn) forint(n25, 0, sn) forn(k, 2) {
		int val=h[i][j][n25][k];
		if(val==0) continue;
		//printf("h[%d,%d,   %d, %d]=%d\n",i,j,n25,k,val);
		if(i+j<sn) {
			if(s[_ i]==s[_(sn-j-1)]) {
				if(i+1+j+1<=sn)
					add(h[i+1][j+1][n25+1][1], val);
				else
					add(h[i+1][j][n25][0], val);
			} else {
				add(h[i+1][j][n25][0], val);
				add(h[i][j+1][n25][0], val);
			}
		} else if(i+j==sn) {
			add(N.a[n25][k], val);
		}
	}
}

struct Mat {
	int a[MAXN][MAXN];
	int n;
	void clear(int n) {
		this->n=n;
		fillchar(a, 0);
	}
	friend Mat mul(const Mat &a, const Mat &b) {
		Mat c; c.clear(a.n);
		forint(i, 1, a.n) forint(j, i, a.n) {
			LL s=0;
			forint(k, 1, a.n) s+=a.a[i][k]*b.a[k][j];
			c.a[i][j]=int(s%MOD);
		}
		return c;
	}
	friend Mat pow(Mat a, LL b) {
		Mat c; c.clear(a.n);
		forint(i, 1, a.n) c.a[i][i]=1;
		for(; b>0; b>>=1, a=mul(a, a)) {
			//printf("powing b=%d\n", (int)b);
			if(b&1) c=mul(a, c);
		}
		return c;
	}
};

struct Automaton {
	int id24[MAXS], id25[MAXS], idt[MAXS];
	int n;
	Mat A, Am0, Am;
	void init(int N24, int N25, LL m) {
	//printf("N24 %d N25 %d\n",N24,N25);
		n=0;
		forintdown(i, N24, 1) id24[i]=++n;
		forint(i, 1, N25) id25[i]=++n;
		forint(i, 0, N25) idt[i]=++n;
		A.clear(n);
		forint(i, 1, N24) add(A.a[id24[i]][id24[i]], 24);
		forint(i, 1, N25) add(A.a[id25[i]][id25[i]], 25);
		forint(i, 0, N25) add(A.a[idt[i]][idt[i]], 26);
		forintdown(i, N24, 2) add(A.a[id24[i]][id24[i-1]], 1);
		add(A.a[id24[1]][id25[1]], 1);
		forint(i, 1, N25-1) add(A.a[id25[i]][id25[i+1]], 1);
		forint(i, 1, N25) add(A.a[id25[i]][idt[i]], 1);
		add(A.a[id24[1]][idt[0]], 1);

		//printf("n=%d m=%d\n", n,(int)m);

		Am0=pow(A, m-1);
		Am=mul(Am0, A);
	}
	int calc(int n24, int n25, int k) {
		// k=0: # paths of len=m
		// k=1: # paths of len=m-1 * 26 (last step should be self loop)
		int i, j;
		if(n24>0) i=id24[n24]; else i=id25[1];
		j=idt[n25];
		int ans=0;
		//printf("calc (%d,%d) [%d]  %d %d\n",n24,n25,k,Am.a[i][j],Am0.a[i][j]);
		if(k==0)
			ans=Am.a[i][j];
		else
			ans=Am0.a[i][j]*26%MOD;
		return ans;
	}
};

int main() {
	string s; LL n;
	cin>>s>>n;
	int sn=(int)s.size();
	n+=sn;
	LL m=(n+1)/2;

	//printf("#1\n");

	static N_struct N;
	compute_N(N, s);
	/*
	if(n%2==0) {
		forint(i, 0, sn) {
			add(N.a[i][0], N.a[i][1]);
			N.a[i][1]=0;
		}
	}
	*/
	//forint(i, 0, sn) forint(k, 0, 1) if(N.a[i][k]) printf("N[%d,%d]=%d\n",i,k,N.a[i][k]);

	static Automaton au;
	au.init(sn, sn/2+1, m);

	//printf("#2\n");

	int ans=0;
	//printf("m=%d\n",(int)m);
	forint(n25, 0, sn) {
		int L=sn-n25; if(L<n25) continue;
		int n24=L-n25;
		forn(k, 2) {
		if(!N.a[n25][k]) continue;
			LL tmp;
			int k2=k;
			if(n%2==0) k2=0;
			if(k==0)
				tmp=au.calc(n24-1, n25+1, k2);
			else
				tmp=au.calc(n24, n25, k2);
		//if(N.a[n25][k]) printf("%d %d %d tmp=%d\n",n24,n25,k,(int)tmp);
			tmp=(tmp*N.a[n25][k])%MOD;
			add(ans, (int)tmp);
		}
	}
	//ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<endl;

	return 0;
}