#include <bits/stdc++.h>
using namespace std;

const int K = 41;

long long mst[K];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	mst[0] = 0;
	for(int i = 1; i < K; i++){
		mst[i] = (mst[i - 1] << 1) + (1LL << (i - 1));
	}
	
	long long n; cin >> n;
	long long answer = 0;
	
	// [0, 2^k1 - 1], [2^k1, 2^{k1 + k2} - 1] .... 
	for(int i = K - 1; i >= 0; i--){
		if((n >> i) & 1){
			n ^= (1LL << i);
			answer += mst[i];
			if(n != 0){
				answer += (1LL << i);
			}
		}
	}
	cout << answer << '\n';

	return 0;
}