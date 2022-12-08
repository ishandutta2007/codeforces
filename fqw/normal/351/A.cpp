#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN=70010;
const int MAXS=70010;
const int MAXT=MAXS / 32 + 1;
#define fi first
#define se second
typedef pair<int,int> PII;
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define fillchar(a, x) memset(a, x, sizeof(a))
typedef unsigned int UL;

int main() {
	double s=0.;
	int n, ni=0;
	scanf("%d", &n);
	forint(i, 1, n*2) {
		double x; scanf("%lf", &x);
		int t=(int)x;
		x-=t;
		while(x<-1E-6) x+=1.;
		while(x>1-1E-6) x-=1.;
		if(x<1E-6) ++ni;
		s+=x;
	}
	//printf("ni=%d\n",ni);
	int min_d=max(0, ni-n);
	int max_d=min(n, ni);
	double ans=1E50;
	forint(d, n-max_d, n-min_d)
		ans=min(ans, fabs(s-(double)d));
	printf("%.3lf\n", ans);
	return 0;
}