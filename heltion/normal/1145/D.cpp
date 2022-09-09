#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 10;
int a[maxn];
int main(){
	int n, m = 32;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		cin >> a[i];
		m = min(m, a[i]);
	}
	cout << 2 + (a[2] ^ m);
}