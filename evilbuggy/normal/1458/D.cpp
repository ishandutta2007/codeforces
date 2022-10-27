#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int up[N << 2], dw[N << 2], a[N];

void solve(){
	string s;
	cin >> s;
	int n = (int)s.size();
	for(int i = 0; i <= n + n; i++){
		up[i] = dw[i] = 0;
	}
	for(int cur = n, i = 0; i < n; i++){
		if(s[i] == '0'){
			up[cur]++;
			cur++;
		}else{
			dw[cur]++;
			cur--;
		}
	}
	int cur = n;
	while(up[cur] || dw[cur]){
		if(up[cur] && dw[cur + 1]){
			cout << '0';
			up[cur]--;
			cur++;
		}else if(dw[cur]){
			cout << '1';
			dw[cur]--;
			cur--;
		}else{
			cout << '0';
			up[cur]--;
			cur++;
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