#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	char c = *min_element(s.begin(), s.end());
	cout << c << ' ';
	bool flg = true;
	for(auto ch : s){
		if(flg && ch == c){
			flg = false;
		}else{
			cout << ch;
		}
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}