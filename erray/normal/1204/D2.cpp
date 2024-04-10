#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	string ans = s;
	int ct = 0;
	for(int i = 0; i < (int)s.size(); ++i){
		if(!ct && s[i] - '0')ans[i] = '0';
		else ct += ((s[i] - '0') ? -1 : 1);
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}