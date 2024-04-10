#include <bits/stdc++.h>

using namespace std;

int n, c[1010], s, t, a, b;

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &c[i]);
		s += c[i];
	}
	
	scanf("%d", &t);
	int best = 999999999;
	for(int i=0; i<t; i++) {
		scanf("%d %d", &a, &b);
		if(s >= a && s <= b) best = min(best, s);
		else if(s <= a) best = min(best,a);
	}
	
	if(best == 999999999) puts("-1");
	else printf("%d\n", best);
		
	return 0;
}