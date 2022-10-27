#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	string t;
	cin >> s;
	cin >> t;
	int answer = 0;
	int n = (int)s.size();
	int m = (int)t.size();
	for(int i = 0; i < n; i++){
		bool flg = true;
		for(int j = 0; j < m; j++){
			if(s[i + j] != t[j]){
				flg = false;
				break;
			}
		}
		if(flg){
			answer++;
			s[i + m - 1] = '#';
		}
	}
	cout << answer << '\n';

	return 0;
}