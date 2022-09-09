//Author: Heltion
//Date: 2019-06-03
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s){cout << s; exit(0);}
constexpr int maxn = 1200000;
int s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, x, m = 0;
	cin >> n >> x;
	set<int> si;
	si.insert(0);
	for(int i = 1; i < (1 << n); i += 1)
		if(not si.count(i ^ x)){
			s[m += 1] = i;
			si.insert(i);
		}
	cout << m << endl;
	for(int i = 1; i <= m; i += 1) cout << (s[i] ^ s[i - 1]) << " ";
	return 0;
}