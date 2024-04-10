#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int a[N], mx[N], ans[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	ans[n - 1] = *max_element(a + 1, a + n + 1);
	
	memset(mx, 0, sizeof(mx));
	for(int i = 1; i <= n; i++){
		int len = min(i - 1, n - i);
		mx[len] = max(mx[len], a[i]);
	}
	for(int i = n - 1; i >= 0; i--){
		mx[i] = max(mx[i], mx[i + 1]);
	}
	for(int i = n - 2; i >= 0; i -= 2){
		ans[i] = mx[(n - 2 - i) >> 1];
	}
	memset(mx, 0, sizeof(mx));
	for(int i = 1; i < n; i++){
		int len = min(i - 1, n - 1 - i);
		mx[len] = max(mx[len], min(a[i], a[i + 1]));
	}
	for(int i = n - 1; i >= 0; i--){
		mx[i] = max(mx[i], mx[i + 1]);
	}
	for(int i = n - 3; i >= 0; i -= 2){
		ans[i] = mx[(n - 3 - i) >> 1];
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';

	return 0;
}