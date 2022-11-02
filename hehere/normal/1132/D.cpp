#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxN = 200000 + 5;
int n, k;
LL a[maxN], b[maxN];

int sum[maxN];
bool test(LL per) {
	memset(sum, 0, sizeof(sum));
	int cnt = k + 10;
	
	for(int i = 1; i <= n && cnt >= 0; ++i) {
		for(int j = 0; j <= k + 10; ++j) {
			LL day = (a[i] + j * per) / b[i] + 1;
			if(day > k) break;
			cnt--;
			sum[day]++;
		}
	}
	
	for(int i = 2; i <= k; ++i) sum[i] += sum[i - 1];
	for(int i = 1; i <= k; ++i) if(sum[i] > i) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k; k--;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];
	LL L = 0, R = *max_element(b + 1, b + n + 1) * k;
	if(!test(R)) cout << -1 << endl;
	else {
		while(L < R) {
			LL M = (L + R) >> 1;
			if(test(M)) R = M;
			else L = M + 1;
		}
		cout << L << endl;
	}
	
	return 0;
}