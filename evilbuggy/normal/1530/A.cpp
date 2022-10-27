#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int answer = 0;
		while(n){
			answer = max(answer, n%10);
			n /= 10;
		}
		cout << answer << '\n';
	}

	return 0;
}