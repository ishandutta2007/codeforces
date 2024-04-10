#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n, d, h;
void solve() {
	scanf("%d %d %d", &n, &d, &h);
	if (d > 2*h){
		printf("-1\n");
		return;
	}

	if (d == 1) {
		if (n != 2) printf("-1\n");
		else printf("1 2\n");
		return;
	}

	int op = d-h;
	if (d == h) {
		int used = 1;
		REP(i,h) {
			printf("%d %d\n", used, used+1);
			used++;
		}
		REP(i, (n-1)-d) {
			printf("2 %d\n", used+1);
			used++;
		}
	}
	else {
		int op = d-h;
		int used = 1;
		REP(i,op) {
			printf("%d %d\n", used, used+1);
			used++;
		}
		printf("1 %d\n", used+1);
		used++;
		REP(i,h-1) {
			printf("%d %d\n", used, used+1);
			used++;
		}
		REP(i, (n-1)-d) {
			printf("1 %d\n", used+1);
			used++;
		}
	}
}

int main() {
    solve();
}