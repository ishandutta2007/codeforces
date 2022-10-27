#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;

long long A[maxN], D[maxN], ZD[maxN], sum;

long long ceil2(long long x){
	if(x >= 0){
		return (x + 1)/2;
	}
	return -(abs(x)/2);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	sum = 0;
	for(int i = 1; i < n; i++){
		D[i] = A[i + 1] - A[i];
		ZD[i] = max(0LL, D[i]);
		sum += ZD[i];
	}
	cout << ceil2(sum + A[1]) << '\n';
	int q;
	cin >> q;
	while(q--){
		int l, r, x;
		cin >> l >> r >> x;
		if(l != 1){
			D[l - 1] += x;
			sum -= ZD[l - 1];
			ZD[l - 1] = max(0LL, D[l - 1]);
			sum += ZD[l - 1];
		}else{
			A[1] += x;
		}
		if(r != n){
			D[r] -= x;
			sum -= ZD[r];
			ZD[r] = max(0LL, D[r]);
			sum += ZD[r];
		}
		cout << ceil2(sum + A[1]) << '\n';
	}

	return 0;
}