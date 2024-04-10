//Author: Heltion
//Date: 10-25-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 200000;
pair<int, int> p[maxn];
void solve(){
	int n;
	LL s;
	cin >> n >> s;
	for(int i = 0; i < n; i += 1) cin >> p[i].first >> p[i].second;
	sort(p, p + n, greater<pair<int, int>>());
	LL L = p[n / 2].first, R = s;
	while(L < R){
		LL M = (L + R + 1) >> 1;
		int cnt = n / 2 + 1;
		LL ns = 0;
		for(int i = 0; i < n; i += 1){
			if(M > p[i].second) ns += p[i].first;
			else if(cnt){
				ns += max(M, (LL)p[i].first);
				cnt -= 1;
			}
			else ns += p[i].first;
		}
		if(ns <= s and not cnt) L = M;
		else R = M - 1;
	}
	cout << L << "\n";
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