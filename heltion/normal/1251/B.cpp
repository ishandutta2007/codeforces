//Author: Heltion
//Date: 10-25-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = -1;
void solve(){
	multiset<int> ms;
	int n;
	cin >> n;
	int cnt[2] = {0, 0};
	for(int i = 0; i < n; i += 1){
		string s;
		cin >> s;
		for(char c : s) cnt[c - '0'] += 1;
		ms.insert(s.size() / 2);
	}
	int p = cnt[0] / 2 + cnt[1] / 2, ans = 0;
	for(int x : ms){
		if(p < x) break;
		p -= x;
		ans += 1;
	}
	cout << ans << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int t;
	for(cin >> t; t; t -= 1) solve();
	return 0;
}