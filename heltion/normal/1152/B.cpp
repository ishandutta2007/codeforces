//Author: Heltion
//Date: 2019-04-24
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
bool check(int n){
	for(int k = 1; k <= n + 1; k <<= 1)
		if(k == n + 1) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, t;
	cin >> x;
	vector<int> v;
	for(t = 0; not check(x); t += 1)
		if(t & 1) x += 1;
		else{
			int n = 0;
			while(x % (1 << (n + 1)) == 0) n += 1;
			v.push_back(n);
			x ^= (1 << n) - 1;
		}
	cout << t << endl;
	for(int x : v) cout << x << " ";
	return 0;
}