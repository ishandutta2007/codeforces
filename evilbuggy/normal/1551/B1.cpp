#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = (int)s.size();
		vector<int> a(26);
		for(int i = 0; i < n; i++){
			a[s[i] - 'a']++;
		}
		int answer = 0, excess = 0;
		for(int i = 0; i < 26; i++){
			if(a[i] == 0)continue;
			if(a[i] == 1){
				excess++;
				if(excess == 2){
					answer++;
					excess = 0;
				}
			}else{
				answer++;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}