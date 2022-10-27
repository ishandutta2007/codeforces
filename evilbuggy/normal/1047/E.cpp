#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000005;
const int mod = 1000000007;

long long A[maxN];
vector<int> g[maxN];
int chk[maxN], dp[maxN];
int cnt1[maxN], cnt2[maxN];

void dfs(int v){
	for(int u : g[v]){
		dfs(u);
		A[v] += A[u];
	}
}

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
		cnt1[i] = 0;
		cnt2[i] = 0;
		chk[i] = dp[i] = 0;
	}
	for(int i = 2; i <= n; i++){
		int p;
		cin >> p;
		g[p].emplace_back(i);
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		long long x = A[1]/__gcd(A[1], A[i]);
		if(x <= n){
			cnt1[x]++;
		}
		if(A[1]%A[i] == 0 && x <= n){
			chk[x] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i){
			cnt2[j] += cnt1[i];
		}
	}
	for(int i = 1; i <= n; i++){
		if(!chk[i])continue;
		if(cnt2[i] != i){
			chk[i] = 0;
		}
	}
	dp[1] = 1;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + i; j <= n; j += i){
			if(chk[j])add(dp[j], dp[i]);
		}
		add(ans, dp[i]);
	}
	cout << ans << '\n';
	
	return 0;
}