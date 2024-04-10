#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
	ios::sync_with_stdio(false);
	int q;
	for(cin >> q; q; q -= 1){
		int n, s = 0;
		cin >> n;
		for(int i = 0, a; i < n; i += 1){
			cin >> a;
			s += a;
		}
		cout << (s + n - 1) / n << "\n";
	}
}