//Author: Heltion
//Date: 2019-05-14
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 2400000;
int a[maxn], L[maxn], R[maxn], FR[maxn], FL[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		if(L[a[i]] == 0) L[a[i]] = i;
		R[a[i]] = i;
	}
	for(int i = 1; i <= x; i += 1){
		if(not L[i]) FR[i] = FR[i - 1];
		else if(L[i] >= FR[i - 1]) FR[i] = max(FR[i - 1], R[i]);
		else FR[i] = n + 1;
		//cout << i << " " << FR[i] << endl;
	}
	if(FR[x] <= n){
		cout << 1LL * x * (x + 1) / 2;
		return 0;
	}
	FL[x + 1] = n + 1;
	for(int i = x; i >= 1; i -= 1){
		if(not R[i]) FL[i] = FL[i + 1];
		else if(R[i] <= FL[i + 1] or not R[i]) FL[i] = min(FL[i + 1], L[i]);
		else FL[i] = 0;
		//cout << i << " " << FL[i] << endl;
	}
	LL ans = 0;
	for(int i = 0, j = 1; i <= x; i += 1){
		while(j <= x and FL[j] <= FR[i]) j += 1;
		if(FR[i] <= n) ans += x - j + 2;
		//cout << i << " " << j << endl;
	}
	cout << ans;
	return 0;
}
//[1,3][4,5][2,7][6,6]