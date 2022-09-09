//Author: SBHeltion
//Date: 2019-06-22
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200;
int a[maxn], p[maxn], t[maxn], l[maxn], r[maxn];
void no(){
	cout << "NO";
	exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i += 1) cin >> t[i] >> l[i] >> r[i];
	for(int i = 0; i < m; i += 1) if(t[i])
		for(int j = l[i] + 1; j <= r[i]; j += 1) p[j] = 1;
	for(int i = 0; i < m; i += 1) if(not t[i]){
		int x = 0;
		for(int j = l[i] + 1; j <= r[i]; j += 1) if(not p[j]) x = 1;
		if(not x) no();
	}
	cout << "YES\n";
	a[0] = 5000;
	for(int i = 1; i <= n; i += 1){
		if(p[i]) a[i] = a[i - 1] + 1;
		else a[i] = a[i - 1] - 1;
		cout << a[i] << " ";
	}
	return 0;
}