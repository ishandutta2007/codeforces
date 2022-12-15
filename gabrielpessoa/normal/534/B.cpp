#include <bits/stdc++.h>
using namespace std;

int maxLen(int v1, int v2, int t, int d) {
	if(v1 + (t - 1)*d < v2 || v2 + (t-1) * d < v1) {
		return -1;
	} else if(t == 1) {
		return v1;
	} else {
		for(int i = d; i >= d * -1; i--) {
			int res = maxLen(v1+i, v2, t - 1, d);
			if(res != -1) {
				return res + v1;
			}
		}
		return -1;
	}
}
int main() {
	int v1, v2, t, d, cur, len;
	scanf("%d %d %d %d", &v1, &v2, &t, &d);
	printf("%d", maxLen(v1, v2, t, d));
	return 0;
}