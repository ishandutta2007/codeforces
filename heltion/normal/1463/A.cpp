#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int f(int a, int b, int c){
	if((a + b + c) % 9) return 0;
	int x = (a + b + c) / 9;
	return a >= x and b >= x and c >= x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	for(cin >> T; T; T -= 1){
		int a, b, c;
		cin >> a >> b >> c;
		cout << (f(a, b, c) ? "Yes\n" : "No\n");
	}
	return 0;
}