//Author: Heltion
//Date: 08-05-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1000;
char s[maxn][maxn + 1];
int cnt[5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i += 1) cin >> s[i];
	int ans = 0;
	for(int i = 0, a; i < m; i += 1){
		cin >> a;
		for(int j = 0; j < 5; j += 1) cnt[j] = 0;
		for(int j = 0; j < n; j += 1) cnt[s[j][i] - 'A'] += 1;
		ans += a * *max_element(cnt, cnt + 5);
	}
	cout << ans;
	return 0;
}