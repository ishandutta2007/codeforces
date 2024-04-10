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
		set<int> st;
		bool flg = false;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(st.count(x))flg = true;
			st.insert(x);
		}
		if(flg)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}