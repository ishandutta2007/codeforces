//Author: Heltion
//Date: 07-24-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
char s[maxn];
int cnt[maxn][9];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		int n, k;
		cin >> n >> k >> (s + 1);
		for(int i = 1; i <= n; i += 1){
			for(int j = 0; j < 9; j += 1) cnt[i][j] = cnt[i - 1][j];
			if(s[i] == 'R') cnt[i][i % 3] += 1;
			if(s[i] == 'G') cnt[i][i % 3 + 3] += 1;
			if(s[i] == 'B') cnt[i][i % 3 + 6] += 1;
		}
		int ans = 0;
		for(int i = 1; i + k - 1 <= n; i += 1){
			ans = max(ans, cnt[i + k - 1][i % 3] - cnt[i - 1][i % 3]
				+ cnt[i + k - 1][(i + 1) % 3 + 3] - cnt[i - 1][(i + 1) % 3 + 3]
				+ cnt[i + k - 1][(i + 2) % 3 + 6] - cnt[i - 1][(i + 2) % 3 + 6]);

			ans = max(ans, cnt[i + k - 1][i % 3 + 3] - cnt[i - 1][i % 3 + 3]
				+ cnt[i + k - 1][(i + 1) % 3 + 6] - cnt[i - 1][(i + 1) % 3 + 6]
				+ cnt[i + k - 1][(i + 2) % 3] - cnt[i - 1][(i + 2) % 3]);


			ans = max(ans, cnt[i + k - 1][i % 3 + 6] - cnt[i - 1][i % 3 + 6]
				+ cnt[i + k - 1][(i + 1) % 3] - cnt[i - 1][(i + 1) % 3]
				+ cnt[i + k - 1][(i + 2) % 3 + 3] - cnt[i - 1][(i + 2) % 3 + 3]);
		}
		cout << k - ans << "\n";
	}
	return 0;
}