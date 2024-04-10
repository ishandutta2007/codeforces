//Author: Heltion
//Date: 2019-05-17
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
bitset<10000> b[50];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m, n;
	cin >> m >> n;
	for(int i = 0; i < m; i += 1){
		int s;
		cin >> s;
		for(int j = 0; j < s; j += 1){
			int a;
			cin >> a;
			b[i].set(a - 1);
		}
	}
	for(int i = 0; i < m; i += 1)
		for(int j = 1; j < m; j += 1) if(not (b[i] & b[j]).count()) no("impossible");
	cout << "possible";
	return 0;
}