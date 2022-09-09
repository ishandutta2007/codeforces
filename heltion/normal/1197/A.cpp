//Author: Heltion
//Date: 07-22-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s = "NO"){cout << s; exit(0);}
constexpr int maxn = 120000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	for(cin >> T; T; T -= 1){
		int n;
		cin >> n;
		for(int i = 0; i < n; i += 1) cin >> a[i];
		sort(a, a + n);
		reverse(a, a + n);
		cout << min(a[1] - 1, n - 2) << "\n";
	}
	return 0;
}