#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int M = 1000005;
const int mod = 1000000007;

int dp[N], lpf[M];

void init(){
	memset(lpf, -1, sizeof(lpf));
	for(int i = 2; i*i < M; i++){
		if(lpf[i] == -1){
			for(int j = i*i; j < M; j += i){
				if(lpf[j] == -1)lpf[j] = i;
			}
		}
	}
	for(int i = 2; i < M; i++){
		if(lpf[i] == -1)lpf[i] = i;
	}
}

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

vector<int> fac;
vector<pair<int, int> > pd;

void dfs(int ind, int val, int lim){
	if(ind == (int)pd.size()){
		fac.emplace_back(val);
		return;
	}
	dfs(ind + 1, val, lim);
	for(int i = 0; i < pd[ind].second; i++){
		val *= pd[ind].first;
		if(val > lim)break;
		dfs(ind + 1, val, lim);
	}
}

void get(int x, int i){
	pd.clear();
	while(x > 1){
		int y = lpf[x];
		pd.emplace_back(y, 0);
		while(x%y == 0){
			pd.back().second++;
			x /= y;
		}
	}
	fac.clear();
	dfs(0, 1, i);
	sort(fac.rbegin(), fac.rend());
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	int answer = 0; dp[0] = 1;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		get(x, i);
		for(auto y : fac){
			add(answer, dp[y - 1]);
			add(dp[y], dp[y - 1]);
		}
	}
	cout << answer << '\n';

	return 0;
}