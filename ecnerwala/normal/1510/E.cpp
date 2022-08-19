#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	using ld = long double;
	ld tx, ty;
	cin >> tx >> ty;
	vector<map<tuple<int,int,int,int>, tuple<int,int,int,int> > > dp(n/2+1);
	dp[0][{0, 0, 0, 0}] = {-1, -1, -1, -1};
	int m2 = 0, m3 = 0, m4 = 0;
	for(int x = 0; x < n/2; x++){
		for(auto [k, _] : dp[x]){
			auto [loc, area, xsum, ysum] = k;
			m2 = max(m2, area);
			m3 = max(m3, xsum);
			m4 = max(m4, ysum);
			for(int dir : {-1, 1}){
				int nloc = loc + dir;
				if(nloc < 0) continue;
				if(nloc > n - (x+1)) continue;
				int b = min(nloc, loc);
				int narea = area + (loc + nloc);
				int nxsum = xsum;
				int nysum = ysum;
				nxsum += 3 * b * (2*x+1);
				nysum += 3 * b * b;
				nxsum += 3*x + (dir == -1 ? 1 : 2);
				nysum += 3*b+1;
				dp[x+1][{nloc, narea, nxsum, nysum}] = {loc, area, xsum, ysum};
			}
		}
	}
	auto solve = [&](tuple<int,int,int,int> v) -> string {
		string res;
		auto cur = v;
		vector<int> z = {get<0>(cur)};
		for(int i = n/2 - 1; i >= 0; i--){
			cur = dp[i+1][cur];
			int a = get<0>(cur);
			if(a == z.back() + 1){
				res += ')';
			} else {
				res += '(';
			}
			z.push_back(a);
		}
		reverse(res.begin(), res.end());
		return res;
	};
	for(int tarea = 1; tarea <= 800; tarea++){
		int nx = int(tx * tarea * 3 + 0.5);
		int ny = int(ty * tarea * 3 + 0.5);
		ld x = ld(nx) / ld(tarea) / 3.0;
		ld y = ld(ny) / ld(tarea) / 3.0;
		if(abs(x - tx) <= 2e-8 && abs(y - ty) <= 2e-8){
		} else {
			continue;
		}
		for(auto [k, _] : dp[n/2]){
			auto [loc, area, xsum, ysum] = k;
			int oarea = tarea - area;
			int oxsum = 3 * n * oarea - (nx - xsum);
			int oysum = ny - ysum;
			if(dp[n/2].count({loc, oarea, oxsum, oysum})){
				string p1 = solve({loc, area, xsum, ysum});
				string p2 = solve({loc, oarea, oxsum, oysum});
				reverse(p2.begin(), p2.end());
				for(char& c : p2){
					if(c == '('){
						c = ')';
					} else if(c == ')'){
						c = '(';
					}
				}
				cout << p1 << p2 << '\n';
				exit(0);
			}
		}
	}
	// cerr << m2 << ' ' << m3 << ' ' << m4 << '\n';
	// cerr << dp[n].size() << '\n';
	// for(auto [k, _] : dp[n]){
	// 	auto [loc, area, xsum, ysum] = k;
	// 	if(loc != 0) continue;
	// 	ld f = area;
	// 	ld x = xsum / f / 3.0;
	// 	ld y = ysum / f / 3.0;
	// 	if(abs(x - tx) <= 2e-8 && abs(y - ty) <= 2e-8){
	// 		string res;
	// 		vector<int> z = {0};
	// 		auto cur = k;
	// 		for(int i = n-1; i >= 0; i--){
	// 			cur = dp[i+1][cur];
	// 			int a = get<0>(cur);
	// 			if(a == z.back() + 1){
	// 				res += ')';
	// 			} else {
	// 				res += '(';
	// 			}
	// 			z.push_back(a);
	// 		}
	// 		reverse(res.begin(), res.end());
	// 		cout << res << '\n';
	// 		exit(0);
	// 	}
	// }
	assert(false);
}