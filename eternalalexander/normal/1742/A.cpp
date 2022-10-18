#include <bits/stdc++.h>

int a,b,c;

void solve() {
	scanf("%d%d%d",&a,&b,&c);
	if ( (a + b == c) || (a + c == b) || (b + c == a) ) puts("YES");
	else puts("NO");
	
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}