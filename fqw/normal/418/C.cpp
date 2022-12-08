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

LL a[111][111];
LL p[111], q[111];
int n, m;

void gen(int len, LL q[]) {
	if(len==1) q[1]=1;
	else if(len==2) q[1]=3, q[2]=4;
	else {
		forint(i, 1, len-1) q[i]=2;
		q[len]=len-2;
	}
}

int main() {
	cin>>n>>m;
	gen(n, p); gen(m, q);
	forint(i, 1, n) forint(j, 1, m) a[i][j]=p[i]*q[j];
	forint(i, 1, n) {
		forint(j, 1, m) cout<<a[i][j]<<" "; cout<<endl;
	}

	return 0;
}