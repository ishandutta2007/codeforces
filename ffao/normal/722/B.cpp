#include <stdio.h>
#include <bits/stdc++.h>

 
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


int n;
int c[110];
char s[110000];
char v[10];

void solve() {
	scanf("%d", &n);
	strcpy(v, "aeiouy");

	REP(i,n) scanf("%d", &c[i]);
	gets(s);
	REP(i,n) {
		gets(s);
		int tc = 0;
		for (int j = 0; s[j]!='\0'; j++) {
			for (int k = 0; k < 6; k++) {
				if (s[j] == v[k]) tc++;
			}
		}

		if (tc != c[i]) {
			printf("NO\n");
			return;
		}
	}

	printf("YES\n");
}


int main() {
    solve();
}