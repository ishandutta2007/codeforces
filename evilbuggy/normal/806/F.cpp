#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;

const int K = 16;
const long double PI = acos(-1.0);

cd base[1 << K], ibase[1 << K];

void init(){
	for(int i = 0; i < (1 << K); i++){
		long double ang = 2*PI*i/(1 << K);
		base[i] = cd(cos(ang), sin(ang));
		ibase[i] = cd(cos(ang), -sin(ang));
	}
}

inline void fft(vector<cd> &a, bool inv){
	int n = (int)a.size();
	for(int i = 1, j = 0; i < n; i++){
		int bit = n >> 1;
		while(j & bit){
			j ^= bit;
			bit >>= 1;
		}
		j ^= bit;
		if(i < j){
			swap(a[i], a[j]);
		}
	}
	for(int len = 2; len <= n; len <<= 1){
		int hlen = len >> 1, diff = (1 << K)/len;
		for(int i = 0; i < n; i += len){
			int cur = 0;
			for(int j = 0; j < hlen; j++){
				cd u = a[i + j];
				cd v = a[i + j + hlen]*(inv?ibase[cur]:base[cur]);
				a[i + j] = u + v;
				a[i + j + hlen] = u - v;
				cur += diff;
			}
		}
	}
	if(inv){
		for(int i = 0; i < n; i++){
			a[i] /= n;
		}
	}
}

inline vector<int> brute(vector<int> &a, vector<int> &b, int n, int mod){
	vector<int> ret(a.size() + b.size());
	for(int i = 0; i < (int)a.size(); i++){
		for(int j = 0; j < (int)b.size(); j++){
			ret[i + j] += a[i]*1LL*b[j]%mod;
			if(ret[i + j] >= mod)ret[i + j] -= mod;
		}
	}
	if(ret.size() > n)ret.resize(n);
	return ret;
}

inline vector<int> multiply(vector<int> &a, vector<int> &b, int n, int mod){
	if(a.size()*1LL*b.size() < 5000000){
		return brute(a, b, n, mod);
	}
	int sz = 1;
	while(a.size() + b.size() > sz)sz <<= 1;
	vector<cd> fa(a.begin(), a.end());
	vector<cd> fb(b.begin(), b.end());
	fa.resize(sz);
	fb.resize(sz);
	fft(fa, false);
	fft(fb, false);
	for(int i = 0; i < sz; i++){
		fa[i] *= fb[i];
	}
	fft(fa, true);
	vector<int> ret(min(n, sz));
	for(int i = 0; i < n && i < sz; i++){
		long long tmp = round(fa[i].real());
		ret[i] = tmp%mod; if(ret[i] < 0)ret[i] += mod;
	}
	return ret;
}

inline vector<int> extend(vector<int> &a, int n, int mod){
	int sz = (int)a.size();
	vector<int> ret(sz + 2);
	for(int i = 0; i < sz; i++){
		ret[i] = a[i];
	}
	for(int i = 0; i < sz; i++){
		ret[i + 1] += a[i]; if(ret[i + 1] >= mod)ret[i + 1] -= mod;
		ret[i + 1] += a[i]; if(ret[i + 1] >= mod)ret[i + 1] -= mod;
	}
	for(int i = 0; i < sz; i++){
		ret[i + 2] += a[i]; if(ret[i + 2] >= mod)ret[i + 2] -= mod;
	}
	if(ret.size() > n)ret.resize(n);
	return ret;
}

inline vector<int> reduce(vector<int> &a, int n, int mod){
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		b[i] = (i + 1)%mod;
		if(i&1){
			if(b[i])b[i] = mod - b[i];
		}
	}
	return multiply(a, b, n, mod);
}

vector<int> pws[60];

inline int getSum(vector<int> &poly, int mod){
	int ret = 0;
	for(int i = 0; i < (int)poly.size(); i += 2){
		ret += poly[i];
		if(ret >= mod)ret -= mod;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	int n, m, mod;
	cin >> n >> m >> mod;
	vector<int> possibleM;
	for(int k = 1; k < 60; k++){
		if((m >> k) == 0)break;
		possibleM.emplace_back(((m >> k) + 1)/2);
	}
	int limit = 2*((n - 1)/2) + 1;
	if(possibleM.empty()){
		cout << 0 << '\n';
		exit(0);
	}
	sort(possibleM.begin(), possibleM.end());
	assert(possibleM[0] == 1);
	pws[0] = vector<int>({1, 2, 1});
	for(int i = 1; i < (int)possibleM.size(); i++){
		pws[i] = multiply(pws[i - 1], pws[i - 1], limit, mod);
		int cur = possibleM[i - 1] << 1;
		if(cur > possibleM[i]){
			assert(cur == possibleM[i] + 1);
			pws[i] = reduce(pws[i], limit, mod);
			cur--;
		}
		while(cur < possibleM[i]){
			pws[i] = extend(pws[i], limit, mod);
			cur++;
		}
	}
	vector<int> poly({1});
	int answer = getSum(poly, mod);
	for(int i = 1; i < (int)possibleM.size(); i++){
		pws[i - 1][0] += 1; if(pws[i - 1][0] >= mod)pws[i - 1][0] -= mod;
		poly = multiply(pws[i - 1], poly, limit, mod);
		int cur = possibleM[i - 1] << 1;
		if(cur > possibleM[i]){
			assert(cur == possibleM[i] + 1);
			if(poly.size() < pws[i].size())poly.resize(pws[i].size());
			for(int j = 0; j < (int)pws[i].size(); j++){
				poly[j] += mod - pws[i][j];
				if(poly[j] >= mod)poly[j] -= mod;
			}
			cur--;
		}
		while(cur < possibleM[i]){
			poly = extend(poly, limit, mod);
			poly[0] += 1; if(poly[0] >= mod)poly[0] -= mod;
			cur++;
		}
		answer += getSum(poly, mod);
		if(answer >= mod)answer -= mod;
	}
	cout << answer << '\n';

	return 0;
}