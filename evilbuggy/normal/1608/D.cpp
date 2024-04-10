#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;
const int mod = 998244353;

int fac[maxN], ifac[maxN], inv[maxN];

void init(){
	inv[1] = 1;
	fac[0] = ifac[0] = 1;
	fac[1] = ifac[1] = 1;
	for(int i = 2; i < maxN; i++){
		fac[i] = fac[i - 1]*1LL*i%mod;
		inv[i] = (mod - mod/i)*1LL*inv[mod%i]%mod;
		ifac[i] = ifac[i - 1]*1LL*inv[i]%mod;
	}
}

inline int ncr(int n, int r){
	if(r < 0 || n < r)return 0;
	return fac[n]*(ifac[r]*1LL*ifac[n - r]%mod)%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int n;
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	int answer = 0;
	{
		int cntn = 0;
		int cntd = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == "??"){
				cntn += 2;
				cntd += 1;
			}else if(s[i] == "W?" || s[i] == "?W"){
				cntn += 1;
			}else if(s[i] == "B?" || s[i] == "?B"){
				cntn += 1;
				cntd += 1;
			}else if(s[i] == "WW"){
				cntd -= 1;
			}else if(s[i] == "BB"){
				cntd += 1;
			}
		}
		answer = ncr(cntn, cntd);
	}
	{
		int cnta = 0;
		int cntb = 0;
		bool flg = true;
		for(int i = 0; i < n; i++){
			if(s[i] == "??"){
				cnta++;
			}else if(s[i] == "WB" || s[i] == "W?" || s[i] == "?B"){
				cntb++;
			}else if(s[i] == "WW" || s[i] == "BB"){
				flg = false;
			}
		}
		if(flg){
			for(int i = 1; i < n; i++){
				answer -= ncr(cnta, i - cntb);
				if(answer < 0)answer += mod;
			}
		}
	}
	cout << answer << '\n';

	return 0;
}