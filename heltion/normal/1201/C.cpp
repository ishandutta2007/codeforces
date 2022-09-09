//Author: Heltion
//Date: 08-05-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 200000;
LL a[maxn], k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n >> k;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	sort(a, a + n);
	LL ans = 0, sum = 0;
	for(int i = n / 2; i < n; i += 1){
		sum += a[i];
		LL pans = k - (a[i] * (i - n / 2 + 1) - sum);
		if(pans < 0) break;
		pans = a[i] + pans / (i - n / 2 + 1);
		if(i + 1 < n) pans = min(pans, a[i + 1]);
		ans = max(ans, pans);
	}
	cout << ans;
	return 0;
}