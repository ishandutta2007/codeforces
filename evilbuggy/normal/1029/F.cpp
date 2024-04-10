#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a;
	long long b;
	long long c;
	cin >> a >> b; c = a + b;
	vector<long long> faca;
	vector<long long> facb;
	vector<long long> facc;
	for(long long d = 1; d*d <= a; d++){
		if(a%d == 0){
			faca.emplace_back(d);
		}
	}
	for(long long d = 1; d*d <= b; d++){
		if(b%d == 0){
			facb.emplace_back(d);
		}
	}
	for(long long d = 1; d*d <= c; d++){
		if(c%d == 0){
			facc.emplace_back(d);
		}
	}
	long long ans = c + 1;
	for(long long y : facc){
		long long hi = y;
		long long lo = (a + (c/y) - 1)/(c/y);
		int ind = lower_bound(faca.begin(), faca.end(), lo) - faca.begin();
		if(ind < (int)faca.size() && faca[ind] <= hi){
			ans = min(ans, c/y + y);
		}
	}
	for(long long y : facc){
		long long hi = y;
		long long lo = (b + (c/y) - 1)/(c/y);
		int ind = lower_bound(facb.begin(), facb.end(), lo) - facb.begin();
		if(ind < (int)facb.size() && facb[ind] <= hi){
			ans = min(ans, c/y + y);
		}
	}
	ans *= 2;
	cout << ans << '\n';

	return 0;
}