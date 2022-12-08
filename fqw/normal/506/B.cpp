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

const int MAXN=100000;
const int MAXM=100000;

struct UF {
	int f[MAXN];
	UF() { fillchar(f, 0xff); }
	int find(int i) {
		return f[i]<0 ? i : f[i]=find(f[i]);
	}
	void unite(int i, int j) {
		i=find(i), j=find(j);
		if(i!=j) f[i]=j;
	}
};

UF uf;
int n, m;
int deg[MAXN];
VI es[MAXN];
int q[MAXN], ss, tt;
bool cir[MAXN];

int main() {
	scanf("%d%d", &n,&m);
	fillchar(deg, 0);
	forn(i, m) {
		int a, b; scanf("%d%d", &a,&b);
		--a, --b;
		++deg[b], es[a].PB(b);
		uf.unite(a, b);
	}
	int cn=0; // # components
	forn(i, n) if(uf.find(i)==i) ++cn;

	ss=tt=0;
	forn(i, n) if(deg[i]==0) q[tt++]=i;
	while(ss<tt) {
		int i=q[ss++];
		forn(k, es[i].size()) {
			int j=es[i][k];
			if(--deg[j]==0) q[tt++]=j;
		}
	}
	fillchar(cir, false);
	forn(i, n) if(deg[i]>0) cir[uf.find(i)]=true;
	int dn=0; // # components with circle
	forn(i, n) if(uf.find(i)==i && cir[i]) ++dn;

	int ans=n-(cn-dn);
	printf("%d\n", ans);
	return 0;
}