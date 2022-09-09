//Author: Heltion
//Date: 07-31-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
LL sum[maxn], a[maxn];
pair<LL, LL> dg[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= m; i += 1) cin >> dg[i].first >> dg[i].second;
	sort(dg + 1, dg + m + 1);
	for(int i = 1; i <= m; i += 1) sum[i] = sum[i - 1] + dg[i].second;
	for(int i = 1; i <= n; i += 1){
		cout << sum[upper_bound(dg + 1, dg + m + 1, make_pair(a[i], (LL)1e9)) - dg - 1] << " ";
	}
	return 0;
}