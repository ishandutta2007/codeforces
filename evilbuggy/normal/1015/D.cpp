#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, k, s;
	cin >> n >> k >> s;
	if(k*(n - 1) < s || k > s){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n';
		long long d = s/k;
		long long cur = 1;
		for(int i = 0; i < k; i++){
			if(i < s%k){
				d++;
			}
			if(cur + d <= n){
				cur += d;
			}else{
				assert(cur - d >= 1);
				cur -= d;
			}
			cout << cur << ' ';
			if(i < s%k){
				d--;
			}
		}
		cout << '\n';
	}

	return 0;
}