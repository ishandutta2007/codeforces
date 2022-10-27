#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	int answer = 0;
	for(int iter = 0; iter < 1000; iter++){
		for(int i = 0; i < n; i++){
			if(iter >= b[i] && (iter - b[i])%a[i] == 0){
				if(s[i] == '0')s[i] = '1';
				else s[i] = '0';
			}
		}
		int cnt = 0;
		for(auto ch : s){
			if(ch == '1')cnt++;
		}
		answer = max(answer, cnt);
	}
	cout << answer << '\n';

	return 0;
}