#include <bits/stdc++.h>
using namespace std;

int cnt[26];
char buf[50];

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", buf);
		cnt[buf[0] - 'a']++;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++){
		int x = cnt[i] / 2, y = cnt[i] - x;
		ans += x * (x - 1) / 2 + y * (y - 1) / 2;
	}
	printf("%d\n", ans);
	return 0;
}