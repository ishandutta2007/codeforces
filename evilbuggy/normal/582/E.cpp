#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

inline int get(char ch){
	int bit, pos, ret = 0;
	if('a' <= ch && ch <= 'd'){
		pos = ch - 'a';
		bit = 0;
	}else{
		pos = ch - 'A';
		bit = 1;
	}
	for(int mask = 0; mask < (1 << 4); mask++){
		if(((mask >> pos) & 1) == bit){
			ret ^= (1 << mask);
		}
	}
	return ret;
}

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

inline void walshHadamardA(vector<int> &a){
	for(int len = 2; len <= (1 << 16); len <<= 1){
		int hlen = len >> 1;
		for(int i = 0; i < (1 << 16); i += len){
			for(int j = 0; j < hlen; j++){
				int u = a[i + j];
				int v = a[i + j + hlen];
				a[i + j] = v;
				a[i + j + hlen] = u + v;
				if(a[i + j + hlen] >= mod){
					a[i + j + hlen] -= mod;
				}
			}
		}
	}
}

inline void invWalshHadamardA(vector<int> &a){
	for(int len = 2; len <= (1 << 16); len <<= 1){
		int hlen = len >> 1;
		for(int i = 0; i < (1 << 16); i += len){
			for(int j = 0; j < hlen; j++){
				int u = a[i + j];
				int v = a[i + j + hlen];
				a[i + j] = v + mod - u;
				a[i + j + hlen] = u;
				if(a[i + j] >= mod){
					a[i + j] -= mod;
				}
			}
		}
	}
}

inline void walshHadamardO(vector<int> &a){
	for(int len = 2; len <= (1 << 16); len <<= 1){
		int hlen = len >> 1;
		for(int i = 0; i < (1 << 16); i += len){
			for(int j = 0; j < hlen; j++){
				int u = a[i + j];
				int v = a[i + j + hlen];
				a[i + j] = u + v;
				a[i + j + hlen] = u;
				if(a[i + j] >= mod){
					a[i + j] -= mod;
				}
			}
		}
	}
}

inline void invWalshHadamardO(vector<int> &a){
	for(int len = 2; len <= (1 << 16); len <<= 1){
		int hlen = len >> 1;
		for(int i = 0; i < (1 << 16); i += len){
			for(int j = 0; j < hlen; j++){
				int u = a[i + j];
				int v = a[i + j + hlen];
				a[i + j] = v;
				a[i + j + hlen] = u + mod - v;
				if(a[i + j + hlen] >= mod){
					a[i + j + hlen] -= mod;
				}
			}
		}
	}
}

inline vector<int> aProduct(vector<int> a, vector<int> b){
	walshHadamardA(a);
	walshHadamardA(b);
	for(int i = 0; i < (1 << 16); i++){
		a[i] = a[i]*1LL*b[i]%mod;
	}
	invWalshHadamardA(a);
	return a;
}

inline vector<int> oProduct(vector<int> a, vector<int> b){
	walshHadamardO(a);
	walshHadamardO(b);
	for(int i = 0; i < (1 << 16); i++){
		a[i] = a[i]*1LL*b[i]%mod;
	}
	invWalshHadamardO(a);
	return a;
}

vector<int> solve(string &s, int l, int r){
	if(l == r){
		char ch = s[l];
		vector<int> ret(1 << 16);
		if(ch == 'a' || ch == '?')ret[get('a')]++;
		if(ch == 'b' || ch == '?')ret[get('b')]++;
		if(ch == 'c' || ch == '?')ret[get('c')]++;
		if(ch == 'd' || ch == '?')ret[get('d')]++;
		if(ch == 'A' || ch == '?')ret[get('A')]++;
		if(ch == 'B' || ch == '?')ret[get('B')]++;
		if(ch == 'C' || ch == '?')ret[get('C')]++;
		if(ch == 'D' || ch == '?')ret[get('D')]++;
		return ret;
	}
	int m = -1, cnt = 0;
	for(int i = l; i <= r; i++){
		if(s[i] == '(')cnt++;
		if(s[i] == ')')cnt--;
		if(cnt == 0){
			m = i;
			break;
		}
	}
	if(m == r){
		return solve(s, l + 1, r - 1);
	}
	char op = s[m + 1];
	vector<int> le = solve(s, l, m);
	vector<int> ri = solve(s, m + 2, r);
	vector<int> ret(1 << 16);
	if(op == '&' || op == '?'){
		vector<int> tmp = aProduct(le, ri);
		for(int mask = 0; mask < (1 << 16); mask++){
			add(ret[mask], tmp[mask]);
		}
	}
	if(op == '|' || op == '?'){
		vector<int> tmp = oProduct(le, ri);
		for(int mask = 0; mask < (1 << 16); mask++){
			add(ret[mask], tmp[mask]);
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int len = (int)s.size();
	vector<int> cnt = solve(s, 0, len - 1);
	
	int n;
	cin >> n;
	vector<pair<int, int> > reqVals;
	for(int i = 0; i < n; i++){
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		int val = (a << 0) + (b << 1) + (c << 2) + (d << 3);
		reqVals.emplace_back(val, e);
	}
	int ans = 0;
	for(int mask = 0; mask < (1 << 16); mask++){
		bool flg = true;
		for(int i = 0; i < n; i++){
			if(((mask >> reqVals[i].first) & 1) != reqVals[i].second){
				flg = false;
				break;
			}
		}
		if(flg)add(ans, cnt[mask]);
	}
	cout << ans << '\n';

	return 0;
}