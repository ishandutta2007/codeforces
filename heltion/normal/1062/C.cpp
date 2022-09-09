#include<bits/stdc++.h>
#define maxn 120000
#define mod 1000000007
using namespace std;
int pw[maxn] = {1}, s[maxn];
char x[maxn];
int main(){
	int n, q;
	cin >> n >> q >> x;
	for(int i = 0; i < n; i += 1)
		pw[i + 1] = pw[i] * 2 % mod;
	for(int i = 0; i < n; i += 1)
		s[i + 1] = s[i] + (x[i] == '1');
	for(int i = 0; i < q; i += 1){
		int l, r;
		cin >> l >> r;
		int a = s[r] - s[l - 1], b = r - l + 1 - a;
		cout << (pw[a] - 1LL) * pw[b] % mod << endl;
	}
}