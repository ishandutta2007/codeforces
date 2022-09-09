// Author: Heltion
// Date: 2019-04-26
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int c[maxn], s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0, a; i < n; i += 1){
		cin >> a;
		c[a] += 1;
	}
	for(int j = 1; j < maxn; j += 1) s[j] = s[j - 1] + c[j];
	int ans = 0, ansL = 0, ansR = 0;
	for(int L = 1, R = 1; R < maxn; R += 1){
		if(c[R]){
			while(L < R and c[L] < 2) L += 1;
			int l = (c[L - 1] and (c[L] >= 2 or L == R)) ? L - 1 : L;
			if(s[R] - s[l - 1] >= ans){
				ans = s[R] - s[l - 1];
				ansL = l;
				ansR = R;
			}
		}
		if(c[R] < 2) L = R;
	}
	cout << ans << "\n";
	for(int i = ansL; i <= ansR; i += 1){
		for(int j = 0; j < c[i] - 1; j += 1)
		 	cout << i << " ";
	}
	for(int i = ansR; i >= ansL; i -= 1) cout << i << " ";
	return 0;
}