#include <bits/stdc++.h>
using namespace std;

map<int, int> dp, nxt;
map<int, vector<int> > available;

inline int extendedgcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int g = extendedgcd(b, a%b, x1, y1);
	x = y1; y = x1 - (a/b)*y1;
	return g;
}

inline int get(int num, int den, int m){
	int g = __gcd(m, den);
	assert(num%g == 0);

	m /= g;
	num /= g;
	den /= g;
	int x, y;
	extendedgcd(den, m, x, y);
	x %= m; if(x < 0)x += m;
	return num*1LL*x%m;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	set<int> uwuSet;
	for(int i = 0; i < m; i++){
		uwuSet.insert(i);
	}
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		uwuSet.erase(x);
	}
	for(int x : uwuSet){
		available[__gcd(x, m)].emplace_back(x);
	}
	vector<int> vec;
	for(auto p : available){
		int x = p.first;
		int s = p.second.size();
		dp[x] = s; nxt[x] = -1;
		vec.emplace_back(x);
	}
	reverse(vec.begin(), vec.end());
	for(int x : vec){
		int mx = 0, go = -1;
		for(int y : vec){
			if((x < y) && (y%x == 0)){
				if(mx < dp[y]){
					mx = dp[y];
					go = y;
				}
			}
		}
		dp[x] += mx; nxt[x] = go;
	}
	int cur = vec.back();
	for(int x : vec){
		if(dp[x] > dp[cur])cur = x;
	}
	vector<int> answer;
	int prefixproduct = 1;
	while(cur != -1){
		for(int x : available[cur]){
			answer.emplace_back(get(x, prefixproduct, m));
			prefixproduct = x;
		}
		cur = nxt[cur];
	}
	cout << (int)answer.size() << '\n';
	for(int x : answer){
		cout << x << " ";
	}
	cout << '\n';

	return 0;
}