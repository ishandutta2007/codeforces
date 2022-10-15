#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		const int mod = 1e9 + 7;
		int n, p;
		cin >> n >> p;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.begin(), v.end(), greater<int>());
		if(p == 1){
			cout << (n&1) << '\n';
			continue;
		}
		auto fp  = [&](long long b, long long pw){
			long long r = 1;
			for (; pw; pw>>=1, (b *= b)%=mod) {
				if(pw&1)(r *= b)%=mod;
			} 
			return r;
		};
		long long nec = -1;
		vector<pair<int, int>> cur;
		function<void(int)> ins = [&](int a) {
			if(cur.empty())cur.emplace_back(a, 1);
			else {
				if (cur[cur.size() - 1].first == a) {
					int cur_ct = cur[cur.size() - 1].second;
					if(cur_ct == p - 1){
					  cur.pop_back();
						ins(a + 1);
					}
					else ++cur[cur.size() - 1].second;
				} else {
					cur.emplace_back(a, 1);
				}
			}	
		};
		for (int a : v) {
			if (nec == -1) {
				nec = a;
			} else {
				ins(a);
			}
			if (!cur.empty()) {
				if(cur[cur.size() - 1].first == nec){
					nec = -1;
					cur.clear();
				}
			}		
		}
		if(nec == -1){
			cout << 0 << '\n';
			continue;
		}
		long long ans = fp(p, nec);
		for (auto a : cur) {
			ans =((ans - fp(p, a.first)*a.second%mod)%mod + mod)% mod; 
		}
		cout << (ans + (long long)mod*mod)%mod << '\n';
			
	}
}