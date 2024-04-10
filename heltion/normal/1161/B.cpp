//Author: Heltion
//Date: 2019-05-05
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 120000;
set<int> s[maxn];
vector<int> d[maxn];
set<int> ok[maxn];
int dis(int a, int b, int n){
	if(a >= b) return a - b;
	return a + n - b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 2; i < maxn; i += 1)
		for(int j = i; j < maxn; j += i)
			d[j].push_back(i);
	int n, m;
	cin >> n >> m;
	for(int i = 1, a, b; i <= m; i += 1){
		cin >> a >> b;
		a -= 1, b -= 1;
		if(dis(a, b, n) > n / 2) swap(a, b);
		if(dis(a, b, n) * 2 == n){
			s[n / 2].insert(a);
			s[n / 2].insert(b);
		}
		else s[dis(a, b, n)].insert(a);
	}
	int ans = 1;
	for(int i = 1; i <= n / 2; i += 1) if(s[i].size()) {
		int pans = 1e9;
		for(const int &x : d[s[i].size()])
			if(n % x == 0){
				int r = n / x, ok = true;
				for(const int &y : s[i]) if(not s[i].count((y + r) % n)){
					ok = false;
					break;
				}
				if(ok) pans = min(pans, r);
			}
		if(pans > n) no("No");
		ans = 1LL * ans * pans / __gcd(ans, pans);
	}
	if(ans >= n) no("No");
	cout << "Yes";
	return 0;
}