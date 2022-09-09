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
	string s;
	cin >> n >> s;
	int pre = 0;
	for(int i = 0; i < n; i += 1){
		if(s[i] == '('){
			cout << (pre & 1);
			pre += 1;
		} 
		else{
			pre -= 1;
			cout << (pre & 1);
		}
	}
	return 0;
}