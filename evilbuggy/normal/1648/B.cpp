#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000*1000 + 5;
int cnt[maxn];

void solve(){
	int n; cin >> n;
	int c; cin >> c;
	for(int i = 1; i <= c; i++){
		cnt[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		int x; cin >> x; cnt[x]++;
	}
	for(int i = 1; i <= c; i++){
		cnt[i] += cnt[i - 1];
	}
	for(int y = 1; y <= c; y++){
		if(cnt[y] == cnt[y - 1])continue;
		for(int d = 1, l = y; l <= c; d++, l += y){
			if(cnt[min(l + y - 1, c)] != cnt[l - 1] && cnt[d] == cnt[d - 1]){
				cout << "No" << '\n';
				return;
			}
		}
	}
	cout << "Yes" << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}