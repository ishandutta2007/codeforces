// Author: Heltion
// Date: 2019-04-26
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200;
bitset<maxn> a[maxn];
int n, m, ok;
bitset<maxn> b[maxn];
int h[maxn];
bitset<maxn> w;
bitset<maxn> xxx[2];
void test(){
	w = a[0] ^ b[0] ^ xxx[h[0]];
	for(int i = 1; i < n; i += 1){
		h[i] = w.test(0) ^ a[i].test(0) ^ b[i].test(0);
		if((w ^ a[i] ^ b[i] ^ xxx[h[i]]).count()) return;
	} 
	cout << "YES\n";
	for(int i = 0; i < n; i += 1) cout << h[i]; cout << "\n";
	for(int i = 0; i < m; i += 1) cout << w.test(i);
	exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1){ 
			int x;
			cin >> x;
			if(x) a[i].set(j); 
		} 
	for(int i = 0; i < m; i += 1) xxx[1].set(i);
	for(int i = n - 1; ~i; i -= 1)
		for(int j = m - 1; ~j; j -= 1){
			b[i].set(j); 
			h[0] = 0;
			test();
			h[0] = 1;
			test();
		}
	cout << "NO";
	return 0;
}