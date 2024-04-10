#include <bits/stdc++.h>
using namespace std;
int main(){
	int T; scanf("%d", &T);
	while (T--){
		int n, s, t; scanf("%d%d%d", &n, &s, &t);
		int ans = max(min(s, n - t), min(t, n - s));
		printf("%d\n", ans + 1);
	} 
	return 0;
}