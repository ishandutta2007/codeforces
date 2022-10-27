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

	ll k; cin>>k;
	vector<ll> cnt(10, 1);
	ll cur = 1;
	while(cur < k){
		int ind = 0;
		ll nprd = cur/cnt[0]*(cnt[0] + 1);
		for(int i = 1; i < 10; i++){
			ll tmp = cur/cnt[i]*(cnt[i] + 1);
			if(tmp > nprd){
				nprd = tmp;
				ind = i;
			}
		}
		cur = nprd;
		cnt[ind]++;
	}
	string s = "codeforces";
	for(int i = 0; i < 10; i++){
		while(cnt[i]--){
			cout<<s[i];
		}
	}
	cout<<'\n';

	return 0;
}