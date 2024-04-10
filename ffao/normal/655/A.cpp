// hardest problem confirmed
#include <bits/stdc++.h>

 
using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

char aa[2][10];
char bb[2][10];


int st(char cc[2][10]) {
	int p[4];
	int ret = 0;
	REP(i,2) {
		REP(j,2) {
			if (cc[i][j] != 'X') p[cc[i][j]-'A'] = i*2+j;
			else ret += i; 
		}
	}

	REP(i, 3) REP(j,i) if (p[i] < p[j]) ret++;
	return ret%2;
}

void solve() {
	REP(i,2) scanf("%s", aa[i]);
	REP(i,2) scanf("%s", bb[i]);
	printf("%s\n", (st(aa)==st(bb)) ? "YES" : "NO");
}

int main() {
    solve();
}