#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 3e5 + 100;
const int MV = 5 + (1<<20);

using ll = long long;

int N;
int a[MN], p[MN];
int c[2][MV];

int main() {
	scanf("%d", &N);
	for(int i = 0;i < N;i++) scanf("%d", a + i);
	
	for(int i : {0, 1}) for(int j = 0;j < MV;j++) c[i][j] = 0;
	
	p[0] = 0;
	for(int i = 0;i < N;i++) p[i+1] = a[i]^p[i];
	
	ll f = 0LL;
	for(int i = 0;i <= N;i++) {
		int j = i&1;
		f += (c[j][p[i]]++);
	}
	
	printf("%lld\n", f);
	
	return 0;
}