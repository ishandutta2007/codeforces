#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back

const int MAXN=100010;
double A[MAXN];
double B[MAXN];
double S[MAXN];
int n;

int main() {
	scanf("%d", &n);
	B[0]=0.0;
	S[0]=0.0;
	for(int i=1; i<=n; ++i) scanf("%lf", &A[i]);
	for(int i=1; i<=n; ++i) {
		B[i]=(B[i-1]+1)*A[i];
		S[i]=S[i-1]+2*B[i]-A[i];
	}
	printf("%.9lf\n", S[n]);
	return 0;
}