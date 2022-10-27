#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	long long n;
	int ind = -1;
	cin >> n >> k;
	long long excess = 2e18;
	long long answer = 0;
	for(int i = 1; i <= k; i++){
		long long x; cin >> x;
		if(excess > (n%x)){
			answer = n/x;
			excess = n%x;
			ind = i;
		}
	}
	cout << ind << " " << answer << '\n';

	return 0;
}