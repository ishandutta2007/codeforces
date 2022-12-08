#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> T gcd(T a, T b) { return b==0 ? a : gcd(b,a%b); }

int f[1000010];

int main() {
	f[0]=0;
	for(int i=1; i<=1000000; ++i) {
		f[i]=1<<30;
		for(int j=i; j>0; j/=10) {
			setmin(f[i], f[i-j%10]);
		}
		++f[i];
		/*
		if(f[i]>last) {
			printf("f=%d c=%d\n",last,lastcnt);
			last=f[i];
		} else ++lastcnt;
		*/
	}
	int n; scanf("%d", &n); printf("%d\n", f[n]);
	return 0;
}