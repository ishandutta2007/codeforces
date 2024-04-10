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

const int MAXN=1000000+100;

int c[5], n;

int main() {
	fillchar(c, 0);
	scanf("%d", &n);
	forint(i, 1, n) {
		int x; scanf("%d", &x);
		++c[x];
	}
	int ans=1<<30, maxval=ans;
	forint(t, -n, n) {
	//forint(t, -1, -1) {
		//printf("t=%d\n",t);
		int d[5];
		int td=0, tmp=0;
		forint(i, 0, 4) d[i]=c[i];
		d[0]-=t; d[1]+=t;
		td+=t; tmp+=abs(t);
		if(d[0]<0) continue;
		td+=d[1]; tmp+=abs(d[1]);
		d[2]+=d[1]; d[1]-=d[1];
		td+=d[2]; tmp+=abs(d[2]);
		d[3]+=d[2]; d[2]-=d[2];
		d[3]+=td; d[4]-=td; tmp+=abs(td);
		if(d[3]<0 || d[4]<0) continue;
		//forint(i, 0, 4) printf("d[%d]=%d\n",i,d[i]);
		tmp/=2;
		ans=min(ans, tmp);
	}
	if(ans==maxval) ans=-1;
	printf("%d\n", ans);
	return 0;
}