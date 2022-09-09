#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 120000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		if(a[i] < 0) a[i] = - a[i] - 1;
	}
	int j = 0;
	if(n & 1){
		j = 1;
		for(int i = 1; i <= n; i += 1) if(a[i] > a[j]) j = i;
	}
	for(int i = 1; i <= n; i += 1)
		if(i != j) cout << - a[i] - 1 << " ";
		else cout << a[i] << " ";
	return 0;
}