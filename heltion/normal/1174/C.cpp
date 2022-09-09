//Author: Heltion
//Date: 2019-06-03
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s){cout << s; exit(0);}
constexpr int maxn = 120000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, c = 0;
	cin >> n;
	for(int i = 2; i <= n; i += 1) if(not a[i]){
		c += 1;
		for(int j = i; j <= n; j += i){
			a[j] = c;
		}
	}
	for(int i = 2; i <= n; i += 1) cout << a[i] << " ";
	return 0;
}