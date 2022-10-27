#include <bits/stdc++.h>
using namespace std;

long long get(long long l, long long n){
	if(l == 0)return 0;
	if(n <= 1)return n;
	long long length = 0;
	for(int i = 60; i >= 0; i--){
		if((n >> i) & 1){
			length = (1LL << i) - 1;
			break;
		}
	}
	if(l <= length)return get(l, n >> 1);
	if(l == length + 1)return (n >> 1) + (n&1);
	return (n >> 1) + (n&1) + get(l - length - 1, n >> 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, l, r;
	cin >> n >> l >> r;
	cout << get(r, n) - get(l - 1, n) << '\n';

	return 0;
}