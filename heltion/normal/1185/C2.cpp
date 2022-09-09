//Author: Heltion
//Date: 2019-06-19
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int c[120];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	for(int i = 1, s = 0; i <= N; i += 1){
		int t;
		cin >> t;
		if(s + t <= M) cout << "0 ";
		else{
			for(int j = 100, ps = s + t, ans = 0; j >= 1; j -= 1){
				int x = (ps - M + j - 1) / j;
				if(x <= c[j]){
					cout << ans + x << " ";
					break;
				}
				ans += c[j];
				ps -= c[j] * j;
			}
		}
		s += t;
		c[t] += 1;
	}
	return 0;
}