#include <bits/stdc++.h>
using namespace std;

char buf[1010];
string s;

int main(){
	int n; scanf("%d", &n);
	scanf("%s", buf), s = buf;
	int sum[2] = {};
	for (int i = 0; i < n; i++){
		sum[s[i] == 'H']++;
	}
	int res = 0x3f3f3f3f;
	for (int i = 0; i < n; i++){
		int cnt = 0;
		for (int j = i; j < i + sum[0]; j++){
			if (s[j % n] != 'T') cnt++;
		}
		for (int j = i + sum[0]; j < i + n; j++){
			if (s[j % n] != 'H') cnt++;
		}
		res = min(res, cnt / 2);
	}
	printf("%d\n", res);
	return 0;
}