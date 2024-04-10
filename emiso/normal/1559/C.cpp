#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

	ans = -1;
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if(i && a[i] == 1 && a[i-1] == 0) ans = i - 1;
	}
	if(a[n-1] == 0) ans = n-1;

	if(a[0] == 1) {
		printf("%lld ", n + 1);
		for(int i = 0; i < n; i++) {
			printf("%d ", i + 1);
		}
		puts("");
	}
	else if(ans == -1) assert(false);
	else {
		for(int i = 0; i < n; i++) {
			printf("%d ", i + 1);
			if(ans == i) printf("%lld ", n + 1);
		}
		puts("");
	}

    if(--t) goto st;
    return 0;
}