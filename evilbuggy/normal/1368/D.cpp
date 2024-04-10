#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	vector<int> cnt(20, 0);
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		for(int j = 0; j < 20; j++){
			if((x >> j) & 1)cnt[j]++;
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int x = 0;
		for(int j = 0; j < 20; j++){
			if(cnt[j]){
				x ^= (1<<j);
				cnt[j]--;
			}
		}
		ans += x*1LL*x;
	}
	cout<<ans<<'\n';

	return 0;
}