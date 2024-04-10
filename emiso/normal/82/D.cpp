#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

int a[1010];
pair <int, int> dp[1010][1010];

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}

	if(n == 1) {
		printf("%d\n1\n",a[0]);
		return 0;
	}
	if(n == 2) {
		printf("%d\n1 2\n", max(a[0], a[1]));
		return 0;
	}

	if(n % 2 == 0) {
		n++;
	}

	for(int i=0;i<n+2;i++) {
		for(int j=0;j<n+2;j++) {
			dp[i][j] = {1100000000, -1};
		}
	}

	dp[1][0].F = 0;
	for(int i = 1; i < n; i += 2) {
		for(int rem = 0; rem < i; rem++) {
			if(dp[i + 2][rem].F > dp[i][rem].F + max(a[i], a[i+1])) {
				dp[i + 2][rem].F = dp[i][rem].F + max(a[i], a[i+1]);
				dp[i + 2][rem].S = rem;
			}

			if(dp[i + 2][i].F > dp[i][rem].F + max(a[rem], a[i+1])) {
				dp[i + 2][i].F = dp[i][rem].F + max(a[rem], a[i+1]);
				dp[i + 2][i].S = rem;
			}
	
			if(dp[i + 2][i+1].F > dp[i][rem].F + max(a[rem], a[i])) {
				dp[i + 2][i+1].F = dp[i][rem].F + max(a[rem], a[i]);
				dp[i + 2][i+1].S = rem;
			}

		}
	}

	int ans = 1100000000, last, last_used = -1;
	stack<int> pilha;

	for(int i=0;i<n;i++) {
		if(ans > dp[n][i].F + a[i]) {
			ans = dp[n][i].F + a[i];
			last = i;
		}
	}

	pilha.push(last);
	last_used = last;
	last = dp[n][last].S;
	int tmp = n - 2;

	while(last != -1 && tmp >= 0) {
		if(last != last_used) pilha.push(last);
		if(tmp != last_used) pilha.push(tmp);
		if(tmp + 1 != last_used) pilha.push(tmp + 1);



		last_used = last;
		last = dp[tmp][last].S;
		tmp -= 2;
	}

	printf("%d\n", ans);
	while(!pilha.empty()) {
		int f, s;
		f = pilha.top(); pilha.pop();
		if(pilha.empty()) {
			if(a[f])
				printf("%d\n", f + 1);
		}
		else {
			s = pilha.top(); pilha.pop();
			printf("%d %d\n", f + 1, s + 1);
		}
	}
	return 0;
}

//dp[6][4] -> dp[4][1] -> dp[2][1];