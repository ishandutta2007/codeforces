#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int maxn = 1200000;
constexpr LL base = 237, mod = 1000000009;
char s[maxn], t[maxn];
LL has[maxn];
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
void no(){
	cout << 0;
	exit(0);
}
int cnt[2];
vector<int> v[2];
bool issame(int p, int q, int L){
	LL has1 = (has[p + L - 1] - has[p - 1] + mod) * power(base, (mod - 2) * p) % mod; 
	LL has2 = (has[q + L - 1] - has[q - 1] + mod) * power(base, (mod - 2) * q) % mod;
	//cout << p << " " << q << " " << L << " " << has1 << " " << has2 << endl;
	return has1 == has2;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> (s + 1) >> (t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	for(int i = 1; i <= n; i += 1) cnt[s[i] - '0'] += 1;
	if(not cnt[0] or not cnt[1]){
		if(m % n) no();
		for(int i = n; i < m; i += n)
			for(int j = 1; j <= n; j += 1)
				if(t[i + j] != t[j]) no();
		cout << 1;
		return 0;
	}
	int ans = 0;
	for(int i = 1; i <= m; i += 1)
		has[i] = (has[i - 1] + power(base, i)  * t[i]) % mod;
	for(int i = 1; i <= m and cnt[0] * i < m; i += 1) if((m - cnt[0] * i) % cnt[1] == 0){
		int w0 = i, w1 = (m - cnt[0] * w0) / cnt[1];
		v[0].clear();
		v[1].clear();
		bool ok = true;
		for(int j = 1, p = 1; j <= n; j += 1) if(s[j] == '0'){
			v[0].push_back(p);
			p += w0;
		}
		else{
			v[1].push_back(p);
			p += w1;
		} 
		if(w0 == w1 and issame(v[0][0], v[1][0], w0)) ok = false;
		//cout << v[0][0] << " " << v[1][0] << " " << ok << endl;
		for(int j = 1; j < cnt[0] and ok; j += 1) if(not issame(v[0][j], v[0][0], w0)) ok = false;
		for(int j = 1; j < cnt[1] and ok; j += 1) if(not issame(v[1][j], v[1][0], w1)) ok = false;
		ans += ok;
	}
	cout << ans;
}