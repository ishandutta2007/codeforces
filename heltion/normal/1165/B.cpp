//Author: Heltion
//Date: 2019-05-14
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	multiset<int> s;
	for(int i = 1, a; i <= n; i += 1){
		cin >> a;
		s.insert(a);
	}
	for(int i = 0; ; i += 1){
		auto it = s.lower_bound(i + 1);
		if(it == s.end()){
			cout << i;
			return 0;
		}
		s.erase(it);
	}
	return 0;
}