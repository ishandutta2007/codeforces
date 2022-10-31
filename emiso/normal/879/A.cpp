#include <bits/stdc++.h>
#define MN 100010

using namespace std;
typedef long long ll;

int t, s, d, T = 0, n;

int main() {			
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &s, &d);
		while(s <= T) s += d;
		T = s;
	}
	
	printf("%d\n", T);
	return 0;
}