#include <bits/stdc++.h>
using namespace std;

const int maxA = 5000005;

long long mem[maxA];
int freq[maxA], cnt[maxA], lpf[maxA];

void init(){
	for(int i = 1; i < maxA; i++){
		lpf[i] = i;
	}
	for(int i = 2; i < maxA; i++){
		if(lpf[i] == i){
			if(i*i > maxA)break;
			for(int j = i*i; j < maxA; j += i){
				if(lpf[j] == j)lpf[j] = i;
			}
		}
	}
}

inline vector<int> factors(int n){
	vector<pair<int, int> > primes;
	
	int m = n;
	while(m > 1){
		int p = lpf[m];
		primes.emplace_back(p, 0);
		while(m%p == 0){
			primes.back().second++;
			m /= p;
		}
	}
	if(m > 1)primes.emplace_back(m, 1);
	
	vector<int> ret({1});
	for(auto x : primes){
		vector<int> nret;
		for(auto y : ret){
			int val = y;
			for(int i = 0; i <= x.second; i++){
				nret.emplace_back(val);
				val *= x.first;
			}
		}
		ret = nret;
	}
	return ret;
}

long long dp(int n){
	if(mem[n] != -1)return mem[n];
	int m = n;
	while(m > 1){
		int p = lpf[m]; m /= p;
		mem[n] = max(mem[n], dp(n/p) + 1LL*(n - n/p)*cnt[n]);
	}
	return mem[n];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int N;
	cin >> N;
	memset(cnt, 0, sizeof(cnt));
	memset(mem, -1, sizeof(mem));
	memset(freq, 0, sizeof(freq));
	for(int i = 1; i <= N; i++){
		int x;
		cin >> x;
		freq[x]++;
	}
	for(int i = 1; i < maxA; i++){
		if(freq[i]){
			vector<int> fac = factors(i);
			for(auto x : fac){
				cnt[x] += freq[i];
			}
		}
	}
	mem[1] = N;
	long long answer = 0;
	for(int i = 1; i < maxA; i++){
		if(freq[i]){
			answer = max(answer, dp(i));
		}
	}
	cout << answer << '\n';

	return 0;
}