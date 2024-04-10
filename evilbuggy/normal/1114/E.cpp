#include <bits/stdc++.h>
using namespace std;

/*
1. "? i" - returns a[i]
2. "> x" - returns 1 if a[i] > x for some i and 0 o.w.

We can find largest element in 30 queries


*/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int cnt = 0;
	int lo = 0, hi = 1000000000;
	while(lo < hi){
		int mi = (lo + hi)/2;
		cout << "> " << mi << endl;
		int x; cin >> x;
		if(x == 1){
			lo = mi + 1;
		}else{
			hi = mi;
		}
		cnt++;
	}
	int diff = 0;
	vector<int> perm(n);
	iota(perm.begin(), perm.end(), 1);
	shuffle(perm.begin(), perm.end(), rng);
	for(int i = 0; i < 60 - cnt && i < n; i++){
		cout << "? " << perm[i] << endl;
		int x; cin >> x;
		diff = __gcd(diff, lo - x);
	}
	cout << "! " << lo - (n - 1)*diff << " " << diff << endl;

	return 0;
}