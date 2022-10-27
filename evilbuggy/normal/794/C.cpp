#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string oleg, igor;
	cin >> oleg >> igor;
	int n = (int)oleg.size();
	sort(oleg.begin(), oleg.end());
	sort(igor.begin(), igor.end());

	string ans = "";
	for(int i = 0; i < n; i++){
		ans += '$';
	}
	int turn = 0;
	int lo = 0, hi = n - 1;
	int olo = 0, ohi = (n + 1)/2 - 1;
	int ilo = ohi + 1, ihi = n - 1;
	while(true){
		if(turn == 0){
			if(lo == hi){
				ans[lo] = oleg[olo];
				break;
			}
			if(oleg[olo] < igor[ihi]){
				ans[lo] = oleg[olo];
				++olo; ++lo;
			}else{
				ans[hi] = oleg[ohi];
				--ohi; --hi;
			}
		}else{
			if(lo == hi){
				ans[lo] = igor[ilo];
				break;
			}
			if(igor[ihi] > oleg[olo]){
				ans[lo] = igor[ihi];
				--ihi; ++lo;
			}else{
				ans[hi] = igor[ilo];
				++ilo; --hi;
			}
		}
		turn ^= 1;
	}
	cout << ans << '\n';

	return 0;
}