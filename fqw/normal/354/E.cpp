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

const int MAXL=20;
const int MAXD=9;

int a[MAXL], len;
bool f[MAXL][MAXD+1];
int fd[MAXL][MAXD+1];
int f4[MAXL][MAXD+1];
int f7[MAXL][MAXD+1];
LL ans[6];

void solve() {
	LL n; cin>>n;
	len=0;
	while(n>0) a[++len]=int(n%10), n/=10;
	fillchar(f, false);
	f[len][0]=true;
	forintdown(i, len, 1) forint(d, 0, MAXD) {
		if(!f[i][d]) continue;
		forint(n4, 0, 6) forint(n7, 0, 6-n4) {
			int c=n4*4+n7*7;
			int e=c/10; c%=10;
			if(c>a[i]) c-=10, ++e;
			if(e==d) {
				f[i-1][a[i]-c]=true;
				fd[i-1][a[i]-c]=d;
				f4[i-1][a[i]-c]=n4;
				f7[i-1][a[i]-c]=n7;
			}
		}
	}
	if(!f[0][0]) printf("-1\n");
	else {
		fillchar(ans, 0);
		LL b=1, d=0;
		forint(i, 0, len-1) {
			int n4=f4[i][d];
			int n7=f7[i][d];
			//printf("i=%d n4=%d n7=%d\n",i,n4,n7);
			forint(j, 0, n4-1) ans[j]+=b*4;
			forint(j, n4, n4+n7-1) ans[j]+=b*7;
		//forint(i, 0, 5) cout<<ans[i]<<" "; cout<<endl;
			d=fd[i][d];
			b*=10;
		}
		forint(i, 0, 5) cout<<ans[i]<<" "; cout<<endl;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}