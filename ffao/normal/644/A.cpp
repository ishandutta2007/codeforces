#include <bits/stdc++.h> 

using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n,a,b;
int la[2]={1,2};

void solve() {
	scanf("%d %d %d", &n, &a, &b);

	if (n > a*b) {
		printf("-1\n");
		return;
	}

	REP(i,a) {
		REP(j,b) {
			int id = (i+j)%2;
			if (la[id] <= n) printf("%d ", la[id]);
			else printf("0 ");
			la[id]+=2;
		}
		printf("\n");
	}
}
int main() {
    solve();
    return 0;
}