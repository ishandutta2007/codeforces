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


int main() {
	int n;
	scanf("%d", &n);
	if(n==1) {printf("YES\n1\n"); return 0;}
	if(n==2) {printf("YES\n1 2\n"); return 0;}
	if(n==3) {printf("YES\n1 2 3\n"); return 0;}
	if(n==4) {printf("YES\n1 3 2 4\n"); return 0;}
	for(int i=2; i*i<=n; ++i)
		if(n%i==0) {
			printf("NO\n"); return 0;
		}
	
	int a=2;
	while(1) {
		int x=a, i=1;
		while(x!=1) x=x*a%n, ++i;
		if(i==n-1) break;
		++a;
	}

	static int pa[100010];
	pa[0]=1;
	forint(i, 1, n) pa[i]=pa[i-1]*a%n;

	printf("YES\n");
	forn(i, n-1) {
		int k=(i%2==0?i:n-1-i);
		printf("%d\n", pa[k]);
	}
	printf("%d\n", n);


	return 0;
}