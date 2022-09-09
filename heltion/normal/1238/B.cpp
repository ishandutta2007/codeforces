//Author: Heltion
//Date: 10-08-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		int n, r;
		cin >> n >> r;
		for(int i = 1; i <= n; i += 1) cin >> a[i];
		sort(a + 1, a + n + 1);
		int L = 1, R = n, ans = 0;
		while(L <= R){
			ans += 1;
			R -= 1;
			while(a[R] == a[R + 1]) R -= 1;
			while(L <= n and a[L] <= ans * r) L += 1;
		}
		cout << ans << "\n";
	}
	return 0;
}