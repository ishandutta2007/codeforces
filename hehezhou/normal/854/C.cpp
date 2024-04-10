#include<bits/stdc++.h>
using namespace std;
int a[300010], n, k;
int t[300010];
long long sum, ans;
priority_queue<pair<int, int> > q;
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n + k; i++) {
		if(i <= n) q.push(make_pair(a[i], i)), sum += a[i];
		if(i > k) sum -= q.top().first, t[q.top().second] = i, q.pop();
		ans += sum;
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) printf("%d ", t[i]);
	puts("");
	return 0;
}