#include <bits/stdc++.h>
using namespace std;

const int K = 45;
int cnt[K], nnt[K], endcnt[K], excess[K];

inline bool check(int n){
	if(cnt[0] < n || cnt[0] > 2*n)return false;
	memset(excess, 0, sizeof(excess));
	memset(endcnt, 0, sizeof(endcnt));
	endcnt[0] = n;
	excess[0] = cnt[0] - n;
	for(int i = 1; i < K; i++){
		if(cnt[i] > 2*endcnt[i - 1]){
			return false;
		}
		if(cnt[i] < endcnt[i - 1]){
			endcnt[i] = cnt[i];
			endcnt[i - 1] -= cnt[i];
		}else{
			endcnt[i] = endcnt[i - 1];
			endcnt[i - 1] = 0;
			excess[i] += cnt[i] - endcnt[i];
		}
	}
	int tot = 0;
	for(int i = K - 1; i >= 0; i--){
		tot += endcnt[i];
		excess[i] += nnt[i];
		if(excess[i] > tot)return false;
		tot -= excess[i];
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	memset(nnt, 0, sizeof(nnt));
	for(int i = 1; i <= n; i++){
		long long x; cin >> x;
		for(int j = K - 1; j >= 0; j--){
			if((x >> j) & 1){
				if(x == (1LL << j)){
					cnt[j]++;
				}else{
					nnt[j]++;
				}
				break;
			}
		}
	}
	vector<int> pos;
	for(int m = 1; m <= n; m++){
		if(check(m))pos.emplace_back(m);
	}
	if(pos.empty()){
		cout << -1 << '\n';
	}else{
		for(auto x : pos){
			cout << x << " ";
		}
		cout << '\n';
	}

	return 0;
}