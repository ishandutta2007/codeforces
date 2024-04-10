//Author: Heltion
//Date: 2019-06-26
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int a[maxn];
vector<int> d[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int q;
	for(int i = 2; i < maxn; i += 1)
		for(int j = i + i; j < maxn; j += i) d[j].push_back(i);
	for(cin >> q; q; q -= 1){
		int n, ans = 0;
		cin >> n;
		for(int i = 0; i < n; i += 1) cin >> a[i];
		sort(a, a + n);
		n = unique(a, a + n) - a;
		set<int, greater<int>> s, ss;
		for(int i = 0; i < n; i += 1){
			ans = max(ans, a[i]);
			for(int x : d[a[i]]) s.erase(x);
			if(s.size()){
				int x = *s.begin();
				ans = max(ans, a[i] + x);
				s.erase(x);
				for(int y : d[x]) s.erase(y);
				if(s.size()) ans = max(ans, a[i] + x + *s.begin());
				for(int y : d[x]) if(ss.count(y)) s.insert(y);
				s.insert(x);
			}
			for(int x : d[a[i]]) if(ss.count(x)) s.insert(x);
			s.insert(a[i]);
			ss.insert(a[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}