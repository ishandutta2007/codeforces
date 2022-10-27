#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		vector<int> p(n);
		for(int i = 0; i < n; i++){
			int x; cin >> x; a[i] = x - 1;
		}
		for(int i = 0; i < n; i++){
			int x; cin >> x; p[x - 1] = a[i];
		}
		int c = 0;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			if(v[i])continue;
			int x = i;
			int l = 0;
			while(!v[x]){
				l++;
				v[x] = 1;
				x = p[x];
			}
			c += l/2;
		}
		long long ans = 0;
		for(int i = 0; i < c; i++){
			ans += 2*(n - 1 - i - i);
		}
		cout << ans << '\n';
	}

	return 0;
}