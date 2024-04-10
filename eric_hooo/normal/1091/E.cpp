#include <bits/stdc++.h>
#define int long long
using namespace std;

long long a[500010], b[500010];
int n;

bool cmp(long long a, long long b){
	return a > b;
}

long long sum[500010];
vector <int> ans;

int can1(int mid){
	int pos = a + n + 2 - upper_bound(a + 1, a + n + 1, mid);
//	cout << "  " << mid << " " << pos << endl;
	int tot = 1;
	for (int i = n; i >= 1; i--){
		if (tot == pos) b[tot++] = mid;
		b[tot++] = a[i];
	}
	if (tot == pos) b[tot++] = mid;
//	cout << "  tot:" << tot << endl;
	for (int i = n + 1; i >= 1; i--){
		sum[i] = sum[i + 1] + b[i];
	}
	int now = n + 2, sum1 = 0;
	for (int k = 1; k <= n + 1; k++){
		sum1 += b[k];
		while (now > k && b[now] < k) now--;
		now++;
//		cout << "    " << 1ll * k * (k - 1) + sum[now] + (now - k - 1) * k << endl;
		if (1ll * k * (k - 1) + sum[now] + (now - k - 1) * k < sum1){
			if (b[k] > mid) return 0;
			return 1;
		}
	}
	return 1;
}

int can2(int mid){
	int pos = a + n + 2 - upper_bound(a + 1, a + n + 1, mid);
//	cout << "  " << mid << " " << pos << endl;
	int tot = 1;
	for (int i = n; i >= 1; i--){
		if (tot == pos) b[tot++] = mid;
		b[tot++] = a[i];
	}
	if (tot == pos) b[tot++] = mid;
//	cout << "  tot:" << tot << endl;
	for (int i = n + 1; i >= 1; i--){
		sum[i] = sum[i + 1] + b[i];
	}
	int now = n + 2, sum1 = 0;
	for (int k = 1; k <= n + 1; k++){
		sum1 += b[k];
		while (now > k && b[now] < k) now--;
		now++;
//		cout << "    " << 1ll * k * (k - 1) + sum[now] + (now - k - 1) * k << endl;
		if (1ll * k * (k - 1) + sum[now] + (now - k - 1) * k < sum1){
			if (b[k] > mid) return 1;
			return 0;
		}
	}
	return 1;
}

main(){
	scanf("%I64d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++){
		scanf("%I64d", &a[i]);
		sum = (sum + a[i]) % 2;
	}
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= n; i++){
		if ((i & 1) == sum) ans.push_back(i);
	}
	
//	for (int i = 0; i < ans.size(); i++){
//		printf("%d ", ans[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < ans.size(); i++){
//		printf("%d ", can1(ans[i]));
//	}
//	printf("\n");
	
	int l = 0, r = ans.size() - 1;
	while (l < r){
//		cout << l << " " << r << " " << ((l + r) >> 1) << endl;
		int mid = (l + r) >> 1;
		if (can1(ans[mid])) r = mid;
		else l = mid + 1;
	}
	int f_l = l;
	l = 0, r = ans.size() - 1;
//	cout << l << " " << r << endl;
	while (l < r){
		int mid = (l + r + 1) >> 1;
//		cout << l << " " << r << " " << mid << endl;
		if (can2(ans[mid])) l = mid;
		else r = mid - 1;
	}
	for (int i = f_l; i <= l; i++){
		printf("%I64d ", ans[i]);
	}
	if (f_l > l) printf("-1");
	printf("\n");
	return 0;
}