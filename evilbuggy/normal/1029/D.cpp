#include <bits/stdc++.h>
using namespace std;

const int D = 10;

inline int diglen(long long x){
	int ret = 0;
	while(x){
		ret++;
		x /= 10;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long k;
	cin >> n >> k;
	vector<long long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	map<long long, int> freq[D + 1];
	for(int i = 0; i < n; i++){
		freq[diglen(a[i])][a[i]%k]++;
	}
	long long ans = 0;
	for(int i = 0; i < n; i++){
		long long x = a[i];
		int len = diglen(a[i]);
		for(int j = 1; j <= D; j++){
			x = (x*10)%k;
			int md = (x == 0)?0:(k - x);
			if(freq[j].count(md))ans += freq[j][md];

			if(j == len){
				if((x + a[i])%k == 0)ans--;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}