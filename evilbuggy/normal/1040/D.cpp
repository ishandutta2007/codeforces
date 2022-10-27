#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline long long randomIndex(long long l, long long r){
	return l + rng()%(r - l + 1);
}

inline bool query(long long l, long long r){
	cout << l << " " << r << endl;
	string s; cin >> s; return s == "Yes";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	long long n;
	cin >> n >> k;
	long long lo = 1, hi = n;
	while(true){
		if(hi - lo + 1 <= 4*k + 4){
			long long ind = randomIndex(lo, hi);
			if(query(ind, ind)){
				exit(0);
			}
		}else{
			long long mi = (lo + hi)/2;
			if(query(lo, mi)){
				hi = mi;
			}else{
				lo = mi + 1;
			}
		}
		hi = min(n, hi + k);
		lo = max(1LL, lo - k);
	}

	return 0;
}