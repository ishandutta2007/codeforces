#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
template<class T> bool setmin(T &a, T b) {
	if(b<a) {a=b; return true;} else return false;
}
template<class T> bool setmax(T &a, T b) {
	if(b>a) {a=b; return true;} else return false;
}
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))

bool g[99][99]; int n, p;

int main() {
	int cs; cin>>cs; while(cs--) {
		cin>>n>>p;
		fillchar(g, false);
		forint(i, 1, n) {
			int j=i;
			(j%=n)+=1; g[i][j]=g[j][i]=true;
			(j%=n)+=1; g[i][j]=g[j][i]=true;
		}
		forint(i, 1, n) forint(j, 1, n)
			if(i!=j && !g[i][j] && p>0) {
				--p;
				g[i][j]=g[j][i]=true;
			}
		forint(i, 1, n) forint(j, i, n)
			if(g[i][j]) cout<<i<<" "<<j<<endl;
	}
	return 0;
}