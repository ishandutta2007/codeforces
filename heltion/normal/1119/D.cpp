#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
void no(){
	cout << "No";
	exit(0);
}
LL a[maxn], b[maxn], s[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	sort(a, a + n);
	n = unique(a, a + n) - a;
	for(int i = 1; i < n; i += 1) b[i] = a[i] - a[i - 1];
	b[n] = 2e18;
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i += 1) s[i] = s[i - 1] + b[i];
	int q;
	cin >> q;
	while(q --){
		LL l, r;
		cin >> l >> r;
		LL k = r - l + 1;
		int p = upper_bound(b + 1, b + n + 1, k) - b;
		cout << s[p - 1] + (n + 1 - p ) * k << " ";
	}
}