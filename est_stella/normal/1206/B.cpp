#include<bits/stdc++.h>
using namespace std;

long long ans, n;
long long mul = 1;
bool flag = false;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i=0; i<n; i++) {
		long long a;
		cin >> a;
		if(a == 0) ans++, flag = true;
		else ans += abs(a - a / abs(a)), mul *= a / abs(a);
	}

	if(mul < 0 && !flag) ans += 2;
	cout << ans;
}