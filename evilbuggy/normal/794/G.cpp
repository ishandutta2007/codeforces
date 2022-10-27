#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int mod = 1000000007;

int nonPeriodic[N], ncr[N << 1], inv[N << 1], mem[N];

void init(int n){
	inv[1] = 1;
	for(int i = 2; i <= n; i++){
		inv[i] = (mod - mod/i)*1LL*inv[mod%i]%mod;
	}
	ncr[0] = 1;
	for(int i = 1; i <= n; i++){
		ncr[i] = ncr[i - 1]*(inv[i]*1LL*(n + 1 - i)%mod)%mod;
	}
	nonPeriodic[0] = 1;
	for(int i = 1; i < N; i++){
		nonPeriodic[i] = nonPeriodic[i - 1] << 1;
		if(nonPeriodic[i] >= mod)nonPeriodic[i] -= mod;
	}
	for(int i = 1; i < N; i++){
		for(int j = i + i; j < N; j += i){
			nonPeriodic[j] += mod - nonPeriodic[i];
			if(nonPeriodic[j] >= mod)nonPeriodic[j] -= mod;
		}
	}
	for(int i = 1; i < N; i++){
		nonPeriodic[i] += nonPeriodic[i - 1];
		if(nonPeriodic[i] >= mod)nonPeriodic[i] -= mod;
	}
}

inline int power(int a, int b){
	int ret = 1;
	while(b){
		if(b&1)ret = ret*1LL*a%mod;
		a = a*1LL*a%mod;
		b >>= 1;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string c, d;
	cin >> c >> d >> n;
	int ca = 0, cb = 0, cq = 0;
	int da = 0, db = 0, dq = 0;
	for(auto ch : c){
		if(ch == 'A')ca++;
		if(ch == 'B')cb++;
		if(ch == '?')cq++;
	}
	for(auto ch : d){
		if(ch == 'A')da++;
		if(ch == 'B')db++;
		if(ch == '?')dq++;
	}
	init(cq + dq);
	int nonoverlapCnt = 0;
	if(c.size() == d.size()){
		nonoverlapCnt = 1;
		for(int i = 0; i < (int)c.size(); i++){
			if(c[i] == '?' && d[i] == '?'){
				nonoverlapCnt <<= 1;
				if(nonoverlapCnt >= mod){
					nonoverlapCnt -= mod;
				}
			}else if(c[i] == '?' || d[i] == '?'){
				// Do nothing
			}else if(c[i] != d[i]){
				nonoverlapCnt = 0;
				break;
			}
		}
	}
	int a = ca - da;
	int b = cb - db;
	long long answer = 0;
	memset(mem, -1, sizeof(mem));
	for(int x = -dq; x <= cq; x++){
		int y = cq - dq - x;
		
		if(a + x == 0 && b + y == 0){
			// do something here
			long long tot = 0;
			for(int r, l = 1; l <= n; l = r + 1){
				r = n/(n/l);
				int k = n/l;
				(tot += (k*1LL*k%mod)*(nonPeriodic[r] + mod - nonPeriodic[l - 1])) %= mod;
			}
			(answer += tot*ncr[x + dq]) %= mod;
			continue;
		}
		
		if(a + x < 0 && b + y < 0)continue;
		if(a + x > 0 && b + y > 0)continue;
		if(a + x == 0 || b + y == 0)continue;
		int g = __gcd(abs(a + x), abs(b + y));
		int m = n/max(abs(a + x)/g, abs(b + y)/g);
		if(mem[m] != -1){
			(answer += mem[m]*1LL*ncr[x + dq]) %= mod;
			continue;
		}
		long long tot = 0;
		for(int r, l = 1; l <= m; l = r + 1){
			r = m/(m/l);
			int k = m/l;
			(tot += k*1LL*(nonPeriodic[r] + mod - nonPeriodic[l - 1])) %= mod;
		}
		mem[m] = tot;
		(answer += tot*ncr[x + dq]%mod) %= mod;
	}
	if(nonoverlapCnt){
		for(int r, l = 1; l <= n; l = r + 1){
			r = n/(n/l);
			int k = n/l;
			long long tmp = (k*1LL*k%mod)*nonoverlapCnt%mod;
			answer -= tmp*(nonPeriodic[r] + mod - nonPeriodic[l - 1])%mod;
			if(answer < 0)answer += mod;
		}
		int tmp = power(2, n + 1) + mod - 2;
		if(tmp >= mod)tmp -= mod;
		answer += nonoverlapCnt*(tmp*1LL*tmp%mod);
		if(answer >= mod)answer -= mod;
	}
	answer %= mod;
	cout << answer << '\n';

	return 0;
}