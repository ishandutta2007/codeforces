//Author: Heltion
//Date: 2019-05-17
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
char v[5] = {'a', 'e', 'i', 'o', 'u'};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int k;
	cin >> k;
	for(int n = 1; n <= k; n += 1) if(k % n == 0){
		int m = k / n;
		if(n >= 5 and m >= 5){
			for(int i = 0; i < n; i += 1) for(int j = 0; j < m; j += 1){
				cout << v[(i + j) % 5];
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}