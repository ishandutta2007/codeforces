#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back

vector<int> a[99];

void build(int d, int l, int r) {
	if(l==r) return;
	int mid=(l+r)/2;
	for(int i=l; i<=mid; ++i) a[d].PB(i);
	build(d+1, l, mid);
	build(d+1, mid+1, r);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; scanf("%d", &n);
	build(1, 1, n);
	int x=0; while(a[x+1].size()>0) ++x;
	printf("%d\n", x);
	for(int i=1; i<=x; ++i) {
		printf("%d", (int)a[i].size());
		for(int j=0; j<(int)a[i].size(); ++j)
			printf(" %d", a[i][j]);
		printf("\n");
	}
	return 0;
}