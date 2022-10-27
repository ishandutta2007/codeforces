#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;

vector<int> g[maxN];
long long S, w[maxN];
int n, L, ans, length[maxN];

void dfslengths(int v, long long sum, vector<long long> &vec){
	vec.push_back(sum);
	sum += w[v];
	{
		int ind = lower_bound(vec.begin(), vec.end(), sum - S) - vec.begin();
		length[v] = min(L, ((int)vec.size()) - ind);
	}
	for(int u : g[v]){
		dfslengths(u, sum, vec);
	}
	sum -= w[v];
	vec.pop_back();
}

int dfs(int v){
	int mxlen = 0;
	for(int u : g[v]){
		mxlen = max(mxlen, dfs(u) - 1);
	}
	if(mxlen == 0){
		mxlen = length[v];
		ans++;
	}
	return mxlen;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> L >> S;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	for(int i = 2; i <= n; i++){
		int p;
		cin >> p;
		g[p].emplace_back(i);
	}
	bool flg = true;
	for(int i = 1; i <= n; i++){
		if(w[i] > S){
			flg = false;
			break;
		}
	}
	if(!flg){
		cout << -1 << '\n';
		exit(0);
	}
	{
		long long sum = 0;
		vector<long long> vec;
		dfslengths(1, sum, vec);
	}
	ans = 0; dfs(1);
	cout << ans << '\n';


	return 0;
}