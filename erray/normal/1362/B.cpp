#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		set<int> s;
		while (n--) {
			int x;
			cin >> x;
			s.insert(x);
		}
		int ans = -1;
		for(int i = 1024; i > 0; --i){
			set<int> ns;
			for(int a : s){
				ns.insert(a^i);
			}
			if(ns == s)ans = i;
		}
		cout << ans << '\n'; 
	}
}