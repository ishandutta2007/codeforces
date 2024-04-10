#include <cstdio>
#include <algorithm>

const int MOD=1e9+7;
const int MAXN=1000000;

using namespace std;

int fi[MAXN+10], sumgcd[MAXN+10], t;
long long c[MAXN+10], dp1[MAXN+10], dp2[MAXN+10];

int main() {
	for (int i=1; i<=MAXN; i++) fi[i]=i;
	for (int i=1; i<=MAXN; i++) for (int j=i*2; j<=MAXN; j+=i) fi[j]-=fi[i];
	for (int i=1; i<=MAXN; i++) for (int j=i; j<=MAXN; j+=i) sumgcd[j]=sumgcd[j]+i*fi[j/i];
	for (long long i=1, dif=0; i<=MAXN; i++) {
		dif=dif+(i-1)*i;
		c[i]=(i*i*i-dif-2*i*(i-1)+2*(sumgcd[i]-i))%MOD;
	}
	dp1[1]=1, dp2[1]=1;
	for (int i=2; i<=MAXN; i++) {
		dp1[i]=(2*(dp1[i-1]+dp2[i-1])-dp1[i-2]-2*dp2[i-2]+10*(long long)MOD+c[i])%MOD;
		dp2[i]=(dp1[i]-dp1[i-1]-dp2[i-1]+2*MOD)%MOD;
	}
	scanf("%d", &t);
	for (int i=0; i<t; i++ ) {
		int n, m;
		scanf("%d%d", &n, &m);
		if (n<m) swap(n, m);
		printf("%d\n", (int) ((dp1[m]+dp2[m]*(n-m))%MOD));
	}
	return 0;
}