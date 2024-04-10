#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back

const int MAXN=100010;

PII a[MAXN];
int n, h;
int ans;


int main() {
	scanf("%d%d", &n,&h);
	for(int i=1; i<=n; ++i) scanf("%d", &a[i].first), a[i].second=i;

	sort(a+1, a+n+1);
	int d1=(a[n].first+a[n-1].first)-(a[1].first+a[2].first);
	int d2a=a[1].first+a[2].first+h, d2b=a[1].first+a[n].first+h;
	if(n>2) {
		d2a=min(d2a, a[2].first+a[3].first);
		d2b=max(d2b, a[n].first+a[n-1].first);
	}
	int d2=d2b-d2a;
	printf("%d\n", min(d1,d2));
	for(int i=1; i<=n; ++i)
		printf("%d%c", (d1>d2&&i==a[1].second)?1:2, i<n?' ':'\n');
	return 0;
}