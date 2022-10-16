#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n, q;

int g[110][110];
int p[10][10];

bool ok(char k) {
	return 'a' <= k && k <= 'f';
}

void solve() {
	scanf("%d %d", &n, &q);

	REP(i,q) {
		char a,b,c;
		scanf(" %c %c %c",&a,&b,&c);
		if (ok(a) && ok(b) && ok(c))
			g[c-'a'][a-'a']++;
	}

	p[0][0] = 1;
	REP(i,n-1){
		REP(j, 6) {
			REP(k, 6) {
				p[i+1][j] += p[i][k] * g[k][j];
			}
		}
	}

	int a = 0;
	REP(i,6) a += p[n-1][i];
	printf("%d\n", a);
}

int main() {
    solve();
}