#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
const int N = 50005;
const int K = 25;

int d[N][K];

int inverse(int n){
	if(n == 1)return 1;
	return (mod - mod/n)*1LL*inverse(mod%n)%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	long long fac = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> d[j][i];
		}
		(fac *= i) %= mod;
	}
	long long total = m*fac%mod;
	for(int j = 1; j <= m; j++){
		vector<int> cnt(n + 2);
		for(int i = 1; i <= n; i++){
			cnt[n + 2 - d[j][i]]++;
		}
		long long value = 1;
		for(int i = 1, cur = 0; i <= n; i++){
			cur += cnt[i];
			(value *= cur) %= mod;
			cur--;
		}
		total += mod - value;
		if(total >= mod)total -= mod;
	}
	for(int i = 2; i <= n; i++){
		(total *= inverse(i)) %= mod;
	}
	cout << total << '\n';

	return 0;
}