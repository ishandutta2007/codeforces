//Author: Heltion
//Date: 2019-05-14
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 960000;
int k[maxn];
vector<int> G[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1) cin >> k[i];
	for(int i = 1, d, t; i <= m; i += 1){
		cin >> d >> t;
		G[d].push_back(t);
	}
	int L = 0, R = maxn;
	while(L < R){
		int M = (L + R) >> 1;
		map<int, int> mp;
		for(int i = 1; i <= n; i += 1) {
			mp[i] = k[i];
		}
		int S = M, C = M;
		for(int i = M; i; i -= 1){
			C = min(C, i);
			for(int t : G[i]){ 
				int h = min(mp[t], C);
				mp[t] -= h;
				C -= h;
				S -= h;
			}
		}
		for(auto p : mp) S -= p.second * 2;
		if(S < 0) L = M + 1;
		else R = M; 
	}
	cout << L;
	return 0;
}