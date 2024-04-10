//Author: Heltion
//Date: 07-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200;
int c[maxn];
void no(){cout << "NO"; exit(0);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n, k, t;
	cin >> n >> k;
	for(int i = 0; i < n; i += 1){
		cin >> t;
		c[t] += 1;
	}
	int s = 0, f = 0, x = (n + 1) / 2;
	for(int i = 1; i <= k; i += 1){
		s += c[i] / 2;
		f += c[i] % 2;
	}
	cout << s * 2 + min(x - s, f);
	return 0;
}