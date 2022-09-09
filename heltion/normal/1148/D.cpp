//Author: Heltion
//Date: 2019-06-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s){cout << s; exit(0);}
constexpr int maxn = 360000;
int a[maxn], b[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int ss = 0, xj = 0;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i] >> b[i];
		if(a[i] < b[i]) ss += 1;
		if(a[i] > b[i]) xj += 1;
	}
	if(ss >= xj){
		vector<int> v;
		for(int i = 1; i <= n; i += 1) if(a[i] < b[i]) v.push_back(i);
		sort(v.begin(), v.end(), [&](const int &x, const int &y){
			return b[x] > b[y];
		});
		cout << ss << "\n";
		for(int x : v) cout << x << " ";
	}
	else{
		vector<int> v;
		for(int i = 1; i <= n; i += 1) if(a[i] > b[i]) v.push_back(i);
		sort(v.begin(), v.end(), [&](const int &x, const int &y){
			return a[x] < a[y];
		});
		cout << xj << "\n";
		for(int x : v) cout << x << " ";
	}
	return 0;
}