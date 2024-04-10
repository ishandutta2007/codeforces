//Author: Heltion
//Date: 2019-05-17
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
vector<int> v[2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// |y - x| <= x < y <= |x + y|
	// |y + x| <= |x| < |y| <= |y - x|
	int n;
	cin >> n;
	for(int i = 0, a; i < n; i += 1){
		cin >> a;
		if(a > 0) v[0].push_back(a);
		if(a < 0) v[1].push_back(-a);
	}
	for(int i = 0; i < 2; i += 1) sort(v[i].begin(), v[i].end());
	LL ans = 0;
	for(int t = 0; t < 2; t += 1)
		for(int i = 0; i < (int)v[t].size(); i += 1){
			ans += upper_bound(v[t].begin(), v[t].end(), v[t][i] * 2) - upper_bound(v[t].begin(), v[t].end(), v[t][i]);
			if(t) ans += upper_bound(v[t ^ 1].begin(), v[t ^ 1].end(), v[t][i] * 2) - lower_bound(v[t ^ 1].begin(), v[t ^ 1].end(), v[t][i]);
			else ans += upper_bound(v[t ^ 1].begin(), v[t ^ 1].end(), v[t][i] * 2) - upper_bound(v[t ^ 1].begin(), v[t ^ 1].end(), v[t][i]);
		}
	cout << ans;
	return 0;
}