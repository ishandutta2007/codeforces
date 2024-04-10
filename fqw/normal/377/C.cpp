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

int f[1<<20];
int s[111];
int n;
int p[22], t[22];

int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%d", s+i);
	sort(s+1, s+n+1, greater<int>());
	int m; scanf("%d", &m); n=m;
	forint(i, 1, n) {
		char s[99];
		scanf("%s%d", s,&t[i]);
		if(s[0]=='b') p[i]=1; else p[i]=2;
	}
	f[(1<<n)-1]=0;
	
	forndown(st, (1<<n)-1) {
		int k=1;
		forn(i, n) if(st&(1<<i)) ++k;
		if(t[k]==1) {
			f[st]=-(1<<30);
			forn(i, n) if((st&(1<<i))==0) {
				int tmp=f[st|(1<<i)];
				//printf("tmp1=%d\n",tmp);
				if(p[k]==2) tmp+=s[i+1];
				//printf("tmp2=%d\n",tmp);
				setmax(f[st], tmp);
			}
		} else {
			f[st]=(1<<30);
			forn(i, n) if((st&(1<<i))==0) {
				int tmp=f[st|(1<<i)];
				//printf("tmp3=%d\n",tmp);
				if(p[k]==2) tmp-=s[i+1];
				//printf("tmp4=%d\n",tmp);
				setmin(f[st], tmp);
			}
		}
		//printf("f[%i]=%d\n",st,f[st]);
	}
	printf("%d\n", f[0]);


	return 0;
}