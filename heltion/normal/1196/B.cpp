//Author: Heltion
//Date: 07-24-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
LL a[maxn], s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i += 1){
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}
		vector<int> ans;
		for(int i = 1, j = 1; i < n and j < k; i += 1)
			if((s[i] - j) % 2 == 0){
				ans.push_back(i);
				j += 1;
			}
		if((int)ans.size() + 1 == k and (s[n] - k) % 2 == 0){
			cout << "YES\n";
			for(int x : ans) cout << x << " ";
			cout << n << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}