#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int mod = 1000000007;

int x[N], pw[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	pw[0] = 1;
	for(int i = 1; i <= n; i++){
		pw[i] = pw[i - 1] << 1;
		if(pw[i] >= mod)pw[i] -= mod;
	}
	sort(x, x + n);
	int answer = 0;
	for(int i = 0; i < n; i++){
		answer += (pw[i] + mod - pw[n - 1 - i])*1LL*x[i]%mod;
		if(answer >= mod)answer -= mod;
	}
	cout << answer << '\n';

	return 0;
}