#include <bits/stdc++.h>
using namespace std;

const int maxN = 2000005;
const int mod = 1000000007;
int lpf[maxN], freq[maxN], maxp[maxN], cntp[maxN], chk[maxN];

void init(){
	memset(lpf, -1, sizeof(lpf));
	memset(freq, 0, sizeof(freq));
	memset(maxp, 0, sizeof(maxp));
	memset(cntp, 0, sizeof(cntp));

	for(int i = 2; i < maxN; i++){
		if(lpf[i] == -1){
			lpf[i] = i;
			if(i > maxN/i)continue;
			for(int j = i*i; j < maxN; j += i){
				if(lpf[j] == -1)lpf[j] = i;
			}
		}
	}
}

inline void update(int x){
	while(x > 1){
		int z = 0;
		int y = lpf[x];
		while(x%y == 0){
			x /= y;
			z++;
		}
		if(maxp[y] < z){
			maxp[y] = z;
			cntp[y] = 1;
		}else if(maxp[y] == z){
			cntp[y]++;
		}
	}
}

inline bool check(int x){
	while(x > 1){
		int z = 0;
		int y = lpf[x];
		while(x%y == 0){
			x /= y;
			z++;
		}
		if(maxp[y] == z && cntp[y] == 1)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int p;
		cin >> p;
		freq[p]++;
	}
	if(freq[2] == n){
		if(n == 1){
			cout << 2 << '\n';
		}else{
			cout << 3 << '\n';
		}
		exit(0);
	}
	int add = 0;
	int mxfreq = *max_element(freq, freq + maxN);
	if(mxfreq > 2 || freq[2] > 1){
		add = 1;
		for(int i = maxN - 1; i >= 2; i--){
			if(lpf[i] != i || freq[i] == 0)continue;
			if(freq[i] == 1){
				if(!maxp[i]){
					update(i);
				}else{
					update(i - 1);
				}
			}else{
				update(i);
				update(i - 1);
			}
		}
	}else{
		for(int i = maxN - 1; i >= 2; i--){
			if(lpf[i] != i || freq[i] == 0)continue;
			if(freq[i] == 1){
				if(!maxp[i]){
					update(i);
				}else{
					update(i - 1);
					chk[i] = 1;
				}
			}else{
				if(maxp[i]){
					add = 1;
				}else{
					update(i);
				}
				update(i - 1);
				chk[i] = 1;
			}
		}
		for(int i = maxN - 1; i >= 2; i--){
			if(lpf[i] != i || freq[i] == 0)continue;
			if(chk[i] == 1 && check(i - 1)){
				add = 1;
			}
		}
	}
	long long ans = 1;
	for(int i = 2; i < maxN; i++){
		while(maxp[i]--){
			ans = ans*i%mod;
		}
	}
	if(add)ans = (ans + 1)%mod;
	cout << ans << '\n';

	return 0;
}