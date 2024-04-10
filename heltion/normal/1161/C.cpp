//Author: Heltion
//Date: 2019-05-05
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i = 1, a; i <= n; i += 1){
		cin >> a;
		mp[a] += 1;
	}
	cout << (mp.begin()->second > n / 2 ? "Bob" : "Alice");
	return 0;
}