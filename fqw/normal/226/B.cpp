#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXN=100010;

LL answer[MAXN];
int a[MAXN], qe[MAXN];
LL sum[MAXN];
int n, q;

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
	scanf("%d", &q);
	for(int i=1; i<=q; ++i) scanf("%d", &qe[i]);
	for(int i=1; i<=n; ++i) a[i]=-a[i];
	sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i) a[i]=-a[i];
	sum[0]=0;
	for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i];

	for(int cur=1; cur<=n; ++cur) {
		LL tmp=0;
		for(int i=1, w=1, k=0; i<=n; i+=w, w=min((LL)w*(LL)cur, (LL)n+1), ++k)
			tmp+=(sum[min(i+w-1, n)]-sum[i-1])*(LL)k;
		answer[cur]=tmp;
	}
	for(int i=1; i<=q; ++i) cout<<answer[min(qe[i],n)]<<" "; cout<<endl;
	return 0;
}