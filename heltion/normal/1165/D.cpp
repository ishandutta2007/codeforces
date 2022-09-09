//Author: Heltion
//Date: 2019-05-14
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 1200000;
LL d[maxn], rd[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	for(cin >> t; t; t -= 1){
		int n, m = 0;
		cin >> n;
		for(int i = 1; i <= n; i += 1) cin >> d[i];
		sort(d + 1, d + n + 1);
		LL x = d[1] * d[n];
		for(LL i = 2; i * i <= x; i += 1) if(x % i == 0){
			rd[m += 1] = i;
			if(i * i != x) rd[m += 1] = x / i;
			if(m > n) break;
		}
		if(n != m){
			cout << "-1\n";
			continue;
		}
		sort(rd + 1, rd + m + 1);
		bool ok = true;
		for(int i = 1; i <= n and ok; i += 1) if(d[i] != rd[i]) ok = false;
		cout << (ok ? x : -1) << "\n";
	}
	return 0;
}