//Author: Heltion
//Date: 07-31-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	string y;
	cin >> n >> y;
	set<int> ans;
	for(int k = 1; k <= n; k += 1) if(n % k == 0){
		bool ok = true;
		for(int i = 0; ok and i < k; i += 1){
			int x = 0;
			for(int j = i; j < n; j += k) x ^= y[j] - '0';
			ok &= not x;
		}
		if(ok) for(int x = k; x <= n; x += k) if(__gcd(x, n) == k) ans.insert(x);
	}
	cout << ans.size();
	return 0;
}