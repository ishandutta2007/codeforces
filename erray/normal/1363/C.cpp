#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		bool b = n&1;
		int ct = 0;
		while(--n){
			int a, b;
			cin >> a >> b;
			ct += a == x;
			ct += b == x;
		}
		cout << (!b || ct <= 1 ? "Ayush" : "Ashish") << '\n';
	}
}