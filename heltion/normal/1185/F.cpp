//Author: Heltion
//Date: 2019-06-19
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
int sum[512], c[maxn], p[512];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1){
		int f, bit = 0;
		cin >> f;
		for(int i = 1; i <= f; i += 1){
			int b;
			cin >> b;
			bit |= 1 << (b - 1);
		}
		for(int j = 1; j < 512; j += 1)
			if((j & bit) == bit) sum[j] += 1;
	}
	for(int i = 1; i <= m; i += 1){
		int r, bit = 0;
		cin >> c[i] >> r;
		for(int i = 1; i <= r; i += 1){
			int a;
			cin >> a;
			bit |= 1 << (a - 1);
		}
		if(p[bit] == 0 or c[i] < c[p[bit]]) p[bit] = i;
	}
	int ans = -1;
	pair<int, int> ansp;
	for(int i = 1; i < 512; i += 1)
		for(int j = i + 1; j < 512; j += 1)
			if(i != j and p[i] and p[j]){
				if(ans < sum[i | j]){
					ans = sum[i | j];
					ansp = make_pair(p[i], p[j]);
				}
				else if(ans == sum[i | j] and c[ansp.first] + c[ansp.second] > c[p[i]] + c[p[j]]){
					ansp = make_pair(p[i], p[j]);
				}
			}
	int mini = 0, smini = 0;
	for(int i = 1; i <= m; i += 1){
		if(mini == 0 or c[mini] >= c[i]){
			smini = mini;
			mini = i;
		}
		else if(smini == 0 or c[smini] >= c[i]){
			smini = i;
		}
	}
	for(int i = 1, k; i < 512; i += 1) if(p[i]){
		if(p[i] == mini) k = smini;
		else k = mini;
		if(ans < sum[i]){
			ans = sum[i];
			ansp = make_pair(p[i], k);
		}
		else if(ans == sum[i] and c[ansp.first] + c[ansp.second] > c[p[i]] + c[k]){
			ansp = make_pair(p[i], k);
		}
	}
	cout << ansp.first << " " << ansp.second;
	return 0;
}