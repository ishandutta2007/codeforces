#include <bits/stdc++.h>
using namespace std;

const int maxN = 300005;

int a[maxN], par[maxN], cnt[maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cnt[0] = 0;
	int cur = 0;
	for(int i = 1; i <= n; i++){
		long long x; cin >> x;
		
		a[i] = 0;
		while(x){
			if(x & 1)a[i]++;
			x >>= 1;
		}
		cur += a[i];
		par[i] = cur & 1;
		cnt[i] = cnt[i - 1] + par[i];
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		int sm = 0, mx = 0;
		for(int j = i; j >= 1; j--){
			if(i - j + 1 >= 128){
				if(par[i]){
					ans += cnt[j - 1];
				}else{
					ans += j - cnt[j - 1];
				}
				break;
			}
			sm += a[j];
			mx = max(mx, a[j]);
			if(sm >= 2*mx && sm%2 == 0){
				ans++;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}