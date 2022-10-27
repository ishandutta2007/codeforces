#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	int q; cin >> q;

	vector<string> a(n, string(m, '.'));

	int cnt = 0, ans = 0;
	auto flip = [&](int x, int y){
		if(a[x][y] == '*'){
			if(a[(cnt - 1)%n][(cnt - 1)/n] == '*')ans++;
			a[x][y] = '.';
			cnt--; ans--;
			if(y*n + x < cnt)ans++;
		}else{
			if(y*n + x < cnt)ans--;
			cnt++; ans++;
			a[x][y] = '*';
			if(a[(cnt - 1)%n][(cnt - 1)/n] == '*')ans--;
		}
	};

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] == '*'){
				flip(i, j);
			}
		}
	}
	for(int i = 0; i < q; i++){
		int x; cin >> x; x--;
		int y; cin >> y; y--;
		flip(x, y);
		cout << ans << '\n';
	}

	return 0;
}