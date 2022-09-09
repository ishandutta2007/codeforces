//Author: Heltion
//Date: 2019-05-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
constexpr int maxn = 120000;
int x[maxn];
set<pair<int, int>> sp;
set<int> si;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= k; i += 1) cin >> x[i];
	for(int i = 1; i <= n; i += 1){
		sp.insert(make_pair(i, i));
		if(i > 1) sp.insert(make_pair(i - 1, i));
		if(i < n) sp.insert(make_pair(i + 1, i));
	}
	for(int i = 1; i <= k; i += 1){
		si.insert(x[i]);
		if(si.count(x[i])) sp.erase(make_pair(x[i], x[i]));
		if(si.count(x[i] - 1)) sp.erase(make_pair(x[i] - 1, x[i]));
		if(si.count(x[i] + 1)) sp.erase(make_pair(x[i] + 1, x[i]));
	}
	cout << sp.size();
	return 0;
}