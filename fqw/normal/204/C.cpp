#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MAXN=200010;

char sa[MAXN], sb[MAXN];
int n;

double cal(vector<int> a, vector<int> b) {
	if(a.size()==0 || b.size()==0) return 0.0;
	double ans=0.0;
	double suml=0.0, sumr=0.0;
	for(int i=0; i<b.size(); ++i) sumr+=(double)(n-b[i]+1);
	for(int i=0, j=0; i<a.size(); ++i) {
		while (j<b.size() && b[j]<a[i]) {
			suml+=(double)b[j];
			sumr-=(double)(n-b[j]+1);
			++j;
		}
		ans+=suml*(double)(n-a[i]+1)+sumr*(double)a[i];
		//printf(" i=%d j=%d suml=%.3lf sumr=%.3lf v1=%.3lf v2=%.3lf\n", i, j, suml, sumr, suml*(double)(n-b[i]+1), sumr*(double)b[i]);
	}
	double ansdiv=0.0;
	for(int i=1; i<=n; ++i) ansdiv+=(double)(n-i+1)*(double)(n-i+1);
	//printf("ans=%.4lf ansdiv=%.4lf\n", ans, ansdiv);
	return ans/ansdiv;
}

int main() {
	scanf("%d%s%s", &n, sa, sb);
	double ans=0.0;
	for(char c='A'; c<='Z'; ++c) {
		vector<int> va, vb;
		for(int i=0; i<n; ++i) if(sa[i]==c) va.push_back(i+1);
		for(int i=0; i<n; ++i) if(sb[i]==c) vb.push_back(i+1);
		ans+=cal(va, vb);
	}
	printf("%.9lf\n", ans);
	return 0;
}