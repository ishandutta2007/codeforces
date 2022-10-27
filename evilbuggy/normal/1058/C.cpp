#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int sum = 0; sum <= 9*n; sum++){
		bool flg = true;
		int cur = 0, cnt = 0;
		for(int i = 0; i < n; i++){
			cur += s[i] - '0';
			if(cur == sum){
				cur = 0;
				cnt++;
			}else if(cur > sum){
				flg = false;
				break;
			}
		}
		if(cnt == 1 || cur != 0)flg = false;
		if(flg){
			cout << "YES" << '\n';
			exit(0);
		}
	}
	cout << "NO" << '\n';

	return 0;
}