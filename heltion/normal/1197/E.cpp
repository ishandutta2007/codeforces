//Author: Heltion
//Date: 07-22-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s = "NO"){cout << s; exit(0);}
constexpr int maxn = 240000;
constexpr LL mod = 1e9+7;
struct fxxk{
	int out, in;
}f[maxn];
bool operator < (const fxxk &a, const fxxk &b){
	if(a.out == b.out) return a.in > b.in;
	return a.out > b.out;
}
map<pair<int, int>, LL> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	//in_k - \sum d
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> f[i].out >> f[i].in;
	sort(f + 1, f + n + 1);
	for(int i = 1; i <= n; i += 1){
		auto it = mp.lower_bound(make_pair(f[i].out, 0));
		if(it == mp.end()) mp[make_pair(f[i].in, f[i].in)] += 1;
		else{
			LL in = 1e18, ans = 0;
			for(; it != mp.end(); it = mp.erase(it)){
				if(it->first.second < in){
					in = it->first.second;
					ans = 0;
				}
				if(it->first.second == in) ans = (ans + it->second) % mod;
			}
			mp[make_pair(f[i].out, in)] = ans;
			mp[make_pair(f[i].in, in - f[i].out + f[i].in)] += ans;
			mp[make_pair(f[i].in, in - f[i].out + f[i].in)] %= mod;
		}
		//cout << f[i].out << " " << f[i].in << ":\n";
		//for(auto p : mp) cout << p.first.first << " " << p.first.second << " " << p.second << endl;
		//cout << "\n";
	}
	LL in = 1e18, ans = 0;
	
	for(auto it = mp.begin(); it != mp.end(); it = mp.erase(it)){
		if(it->first.second < in){
			in = it->first.second;
			ans = 0;
		}
		if(it->first.second == in) ans = (ans + it->second) % mod;
	}
	cout << ans;
	return 0;
}