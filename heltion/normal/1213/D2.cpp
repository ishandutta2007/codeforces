//Author: Heltion
//Date: 08-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;
map<int, vector<int>> mpv;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, k;
	cin >> n >> k;
	for(int i = 0, a; i < n; i += 1){
		cin >> a;
		for(int q = 0; ; q += 1, a /= 2){
			mpv[a].push_back(q);
			if(a == 0) break;
		}
	}
	int ans = 1 << 30;
	for(auto &p : mpv){
		if((int)p.second.size() < k) continue;
		sort(p.second.begin(), p.second.end());
		int pans = 0;
		for(int i = 0; i < k; i += 1) pans += p.second[i];
		ans = min(ans, pans);
	}
	cout << ans << "\n";
	return 0;
}