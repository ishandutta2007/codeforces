#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int prev = -1;
	vector<int> vec;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == 'a'){
			if(prev != -1){
				vec.push_back(i - prev - 1);
			}
			prev = i;
		}
	}
	if(prev == -1){
		cout << 0 << '\n';
		exit(0);
	}
	vec.push_back((int)s.size() - prev - 1);
	long long answer = 0, mul = 1;
	for(int x : vec){
		answer += mul*1LL*x%mod;
		mul = (mul << 1)|1;
		if(mul >= mod){
			mul -= mod;
		}
	}
	answer %= mod;
	cout << answer << '\n';

	return 0;
}