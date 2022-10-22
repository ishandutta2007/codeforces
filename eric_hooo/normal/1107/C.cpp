#include <bits/stdc++.h>
using namespace std;

int a[200010];
char s[200010];
vector <pair <int, int> > all[30];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%s", s);
	int last = 0;
	long long ans = 0;
	for (int i = 1; i < n; i++){
		if (s[i] == s[i - 1]) continue;
		if (i - last <= k){
			for (int j = last; j < i; j++){
				ans += a[j];
			}
		}
		else {
			sort(a + last, a + i), reverse(a + last, a + i);
			for (int j = last; j < last + k; j++){
				ans += a[j];
			}
		}
		last = i;
	}
	if (n - last <= k){
		for (int j = last; j < n; j++){
			ans += a[j];
		}
	}
	else {
		sort(a + last, a + n), reverse(a + last, a + n);
		for (int j = last; j < last + k; j++){
			ans += a[j];
		}
	}
	printf("%I64d\n", ans);
	return 0;
}