#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;
	long long answer = 0;
	for(int i = 0; i < n; i++){
		int ch = s[i] - '0';
		if(ch%2 == 0)answer += i + 1;
	}
	cout << answer << '\n';

	return 0;
}