#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[200010];

bool check(int x){
	int s = k;
	int t = 0;
	for (int i = x; i < n; i++){
		if (s + a[i] > k) t++, s = a[i];
		else s += a[i];
	}
	return t <= m;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int l = 0, r = n - 1;
	while (l < r){
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << n - l << endl;
	return 0;
}