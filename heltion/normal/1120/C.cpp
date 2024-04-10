#include<bits/stdc++.h>
#define maxn 6000
using namespace std;
typedef long long LL;
char s[maxn];
int f[maxn];
bitset<100000007> bs1;
LL base1 = 1007, mod1 = 100000007;
bitset<100000009> bs2;
LL base2 = 1009, mod2 = 100000009; 
bitset<100000013> bs3;
LL base3 = 1013, mod3 = 100000013;
int main(){
	ios::sync_with_stdio(false);
	//cout << (sizeof bs >> 20);
	int n, a, b;
	cin >> n >> a >> b >> (s + 1);
	for(int i = 1; i <= n; i += 1) f[i] = maxn * maxn;
	LL hash1, p1, hash2, p2, hash3, p3;
	for(int i = 1; i <= n; i += 1){
		f[i] = min(f[i], f[i - 1] + a);
		hash1 = hash2 = hash3 = 0;
		for(int j = i; j <= n; j += 1){
			hash1 = (hash1 * base1 + s[j]) % mod1;
			hash2 = (hash2 * base2 + s[j]) % mod2;
			hash3 = (hash3 * base3 + s[j]) % mod3;
			//cout << "->" << i << " " << j << " " << hash << endl;
			if(not bs1.test(hash1) or not bs2.test(hash2) or not bs3.test(hash3)) break;
			f[j] = min(f[j], f[i - 1] + b);
		}
		p1 = p2 = p3 = 1;
		hash1 = hash2 = hash3 = 0;
		for(int j = i; j >= 1; j -= 1){
			hash1 = (hash1 + p1 * s[j]) % mod1;
			hash2 = (hash2 + p2 * s[j]) % mod2;
			hash3 = (hash3 + p3 * s[j]) % mod3;
			//cout << "<-" << j << " " << i << " " << hash << endl;
			bs1.set(hash1);
			bs2.set(hash2);
			bs3.set(hash3);
			p1 = p1 * base1 % mod1;
			p2 = p2 * base2 % mod2;
			p3 = p3 * base3 % mod3;
		}
	}
	cout << f[n];
}