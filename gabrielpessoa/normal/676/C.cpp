#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, best = 0, a = 0, b = 0, i = 0, j = 0;
	char s[100005];
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	while(j < n) {
		if(s[j++] == 'a') {
			a++;
		} else {
			b++;
		}
		if(a > k && b > k) {
			if(s[i++] == 'a') {
				a--;
			} else {
				b--;
			}
		}
		best = max(best, j - i);
	}
	printf("%d", best);
	return 0;
}