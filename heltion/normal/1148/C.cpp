//Author: Heltion
//Date: 2019-06-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s){cout << s; exit(0);}
constexpr int maxn = 360000;
int p[maxn], a[maxn];
vector<pair<int, int>> v;
void sswap(int i, int j){
	swap(a[p[i]], a[p[j]]);
	swap(p[i], p[j]);
	v.push_back(make_pair(i, j));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) {
		cin >> p[i];
		a[p[i]] = i;
	}
	for(int i = 2; i < n; i += 1){
		if(a[i] <= n / 2) sswap(a[i], n);
		else sswap(a[i], 1);
		if(i <= n / 2) {
			if(a[i] == 1) sswap(a[i], n);
		}
		else{
			if(a[i] == n) sswap(a[i], 1);
		}
		sswap(a[i], i);

	}
	if(p[1] != 1) sswap(1, n);
	cout << v.size() << "\n";
	for(auto p : v){
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}