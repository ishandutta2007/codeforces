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

string f[1<<21];
int fl[1<<21];
int p[10];

const int dgs[4]={7,6,4,4};

bool can_add(int x, int y) {
	forndown(i, 4) {
		int c=(1<<dgs[i])-1;
		int a=x&c, b=y&c;
		if(a+b>c) return false;
		x>>=dgs[i], y>>=dgs[i];
	}
	return true;
}

int main() {
	p[0]=0;
	forint(i, 1, 9) {
		int cur=0;
		int x=i; const int d[4]={2, 3, 5, 7};
		forn(j, 4) {
			cur<<=dgs[j];
			while(x%d[j]==0) x/=d[j], cur++;
		}
		p[i]=p[i-1]+cur;
	}

	char a[22]; int n;
	int v=0;
	scanf("%d%s", &n, a);
	forn(i, n) v+=p[int(a[i]-'0')];
	//v=p[9];
	//printf("%d (%d,%d,%d,%d)\n",v,v&31,(v>>5)&31,(v>>10)&31,v>>15);

	fillchar(fl, 0xff);
	fl[0]=0; f[0]="";
	forintdown(i, 9, 2) {
		forn(s, (1<<21)) if(fl[s]>=0 && can_add(s, p[i])) {
			if(fl[s]+1>=fl[s+p[i]]) {
				string tmp=f[s]+char('0'+i);
				if(fl[s]+1>fl[s+p[i]] || tmp>f[s+p[i]]) {
					fl[s+p[i]]=fl[s]+1;
					f[s+p[i]]=tmp;
				}
			}
		}
	}
	printf("%s\n", f[v].c_str());
	return 0;
}