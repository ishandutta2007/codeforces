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

const int MAXN = 500010;

int a[MAXN], lim[MAXN];
int n;

int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	/*
	for(int i=1, j=1; i<=n; ++i) {
		while(j<=n && a[j]<a[i]*2) ++j;
		if(j>n) lim[i]=n*10;
		else lim[i]=j-i;
	}
	forint(i, 2, n) lim[i]=max(lim[i-1], lim[i]);
	int ans=0;
	forint(i, 1, n)
		if(lim[i]<=n-i)
			ans=i;
	*/
	int le=0, ri=n/2;
	while(le<ri) {
		int mid=(le+ri+1)/2;
		bool flag=true;
		forint(i, 1, mid) if(a[i]*2>a[i-mid+n]) flag=false;
		if(flag) le=mid; else ri=mid-1;
	}
	printf("%d\n", n-le);
	return 0;
}