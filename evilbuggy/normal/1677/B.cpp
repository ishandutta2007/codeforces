#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	int m; cin >> m;
	
	string s;
	cin >> s;
	int cnt = 0;
	int sum = 0;
	vector<int> a(m);
	vector<int> b(m);
	for(int i = 0; i < n*m; i++){
		if(a[i%m] == 0 && s[i] == '1'){
			a[i%m] = 1;
			cnt++;
		}
		sum += s[i] - '0';
		if(i >= m)sum -= s[i - m] - '0';

		if(sum > 0){
			b[i%m]++;
		}
		cout << cnt + b[i%m] << ' ';
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