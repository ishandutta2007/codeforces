#include <bits/stdc++.h>
using namespace std;

int main() {
	char s[100005];
	long long int n, k, cur = 0, tempCur = 0;
	scanf("%lld %lld", &n, &k);
	scanf("%s", s);
	while(k-- && cur < n - 1) {
		while(cur < n - 1) {
			if(s[cur] == '4' && s[cur + 1] == '7') {
				if(cur % 2 == 1) {
					if(s[cur-1] == '4') {
						if(k % 2 == 0) {
							s[cur] = '7';
						}
						k = 0;
					} else {
						s[cur] = '7';
					}
				} else {
					s[cur+1] = '4';
					cur++;
				}
				break;
			}
			cur++;
		}
	}
	printf("%s", s);
	return 0;
}