#include <bits/stdc++.h>
using namespace std;

const int N = 15000005;
int lpf[N];

void init(){
	memset(lpf, -1, sizeof(lpf));
	for(int n = 2; n*n < N; n++){
		if(lpf[n] == -1){
			for(int m = n*n; m < N; m += n){
				if(lpf[m] == -1)lpf[m] = n;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	
	int n;
	cin >> n;
	vector<int> a(n);
	int totalgcd = 0;
	for(auto &x : a){
		cin >> x;
		totalgcd = __gcd(totalgcd, x);
	}
	map<int, int> freq;
	for(auto &x : a){
		int y = x/totalgcd;
		while(y > 1){
			if(lpf[y] == -1){
				freq[y]++;
				break;
			}
			int z = lpf[y];
			while(y%z == 0){
				y /= z;
			}
			freq[z]++;
		}
	}
	int ans = n;
	for(auto x : freq){
		ans = min(ans, n - x.second);
	}
	if(ans == n)ans = -1;
	cout << ans << '\n';

	return 0;
}