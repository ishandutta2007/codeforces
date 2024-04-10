#include <bits/stdc++.h>
using namespace std;

inline long long triangleIndex(long long s){
	long long lo = 0, hi = 2000000000LL;
	while(lo <= hi){
		long long mi = (lo + hi)/2;
		long long tmp = mi*(mi + 1)/2;
		if(tmp == s)return mi;
		if(tmp < s){
			lo = mi + 1;
		}else{
			hi = mi - 1;
		}
	}
	return -1;
}

long long query(long long l, long long r){
	cout << "? " << l << " " << r << endl;
	long long x; cin >> x; return x;
}

void solve(){
	int n;
	cin >> n;
	
	long long lo = 1, hi = n;
	long long total = query(1, n);
	
	while(lo < hi){
		long long mi = (lo + hi)/2;
		if(query(1, mi) == total){
			hi = mi;
		}else{
			lo = mi + 1;
		}
	}
	long long k = lo;
	long long len2 = 1 + total - query(1, k - 1);
	long long len1 = 1 + triangleIndex(total - len2*(len2 - 1)/2);
	assert(len1 > 1);
	assert(len2 > 1);
	cout << "! " << k - len1 - len2 + 1 << " " << k - len2 + 1 << " " << k << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}