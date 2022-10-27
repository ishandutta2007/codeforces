#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;
const int mod = 998244353;

int cursum, a[maxN], dp[maxN], sum[maxN];

void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

inline int get(int l, int r){
	int ret = sum[r];
	if(l == 0)return ret;
	if((r - l)&1){
		add(ret, mod - sum[l - 1]);
	}else{
		add(ret, sum[l - 1]);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	stack<int> inds;
	
	a[0] = 0;
	dp[0] = 1;
	sum[0] = 1;
	inds.push(0);
	for(int i = 1; i <= n; i++){
		while(a[inds.top()] > a[i]){
			inds.pop();
		}
		int j = inds.top();
		dp[i] = get(j, i - 1)*1LL*a[i]%mod;
		if(j > 0){
			if	(i%2 == j%2)add(dp[i], dp[j]);
			else add(dp[i], mod - dp[j]);
		}
		sum[i] = dp[i] - sum[i - 1];
		if(sum[i] < 0)sum[i] += mod;
		inds.push(i);
	}
	cout << dp[n] << '\n';

	return 0;
}