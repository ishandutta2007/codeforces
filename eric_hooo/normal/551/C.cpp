#include <bits/stdc++.h>
using namespace std;

long long a[100010];
int n, m, r;

bool check(long long x){
	int tot = m;
	long long s = 0;
	for (int i = 0; i <= r; i++){
		s += a[i];
		while (s + i + 1 >= x){
			s -= x - i - 1;
			tot--;
			if (tot < 0) return 0;
		}
	}
	if (tot == 0) return s <= 0;
	return 1;
}

int main(){
	while (cin >> n >> m){
		long long sum = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
			if (a[i] != 0) r = i;
		}
		long long l = 0, r = sum + n + 1000;
		while (l < r){
			long long mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
	}
	return 0;
}