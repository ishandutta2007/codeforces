#include <bits/stdc++.h>
using namespace std;

inline long long f(long long x){
	long long a = x/3;
	long long b = x/3;
	long long c = x/3;
	if(x%3 >= 1)a++;
	if(x%3 == 2)b++;
	return 2*(a*b + a*c + b*c);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		int lo = 2, hi = (int)1e5;
		while(lo < hi){
			int mi = (lo + hi)/2;
			if(n <= f(mi)){
				hi = mi;
			}else{
				lo = mi + 1;
			}
		}
		cout << lo << '\n';
	}

	return 0;
}