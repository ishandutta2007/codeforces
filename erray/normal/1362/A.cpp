#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		long long a, b;
		cin >> a >> b;
		if(a > b)swap(a, b);
		int ans = 0, ct = 0;
		while(b > a && a <= 1e18/2){
			++ct;
			a<<=1;
			if(ct == 3){
				++ans;
				ct = 0;	
			}
		}
		cout << (a == b ? ans + (ct > 0) : -1) << '\n';
	}
}