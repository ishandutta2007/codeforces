#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	cout << (n*m + 2)/3 << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}