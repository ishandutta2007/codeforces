#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	vector<int> ct(10, 1);
	long long cur = 1;
	for (int i = 0; cur < n; ++ct[i], i = (i + 1) % 10) {
		cur /= ct[i];
		cur *= ct[i] + 1;
	}
	string cf = "codeforces";
	for (int i = 0; i < 10; ++i) {
		while (ct[i]--) cout << cf[i];
	}
}