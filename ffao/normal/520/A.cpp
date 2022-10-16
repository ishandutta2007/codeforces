#include <stdio.h>
#include <bits/stdc++.h>

 
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


char s[1100];
int has[26];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int cnt = 0;

	REP(i,n) {
		int idx;
		if ('A' <= s[i] && s[i] <= 'Z') idx = s[i]-'A';
		else idx = s[i]-'a';

		if (!has[idx]) {
			has[idx] = 1;
			cnt++;
		}
	}

	printf("%s\n", cnt == 26 ? "YES" : "NO");
}


int main() {
    solve();
}