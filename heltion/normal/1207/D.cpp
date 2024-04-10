//Author: Heltion
//Date: 08-22-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 320000;
constexpr LL mod = 998244353;
LL f[maxn];
map<pair<int, int>, int> mpp;
map<int, int> mpa;
map<int, int> mpb;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	for(int i = 0; i < maxn; i += 1) f[i] = i ? f[i - 1] * i % mod : 1LL; 
	int n, a, b;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		cin >> a >> b;
		mpp[{a, b}] += 1;
		mpa[a] += 1;
		mpb[b] += 1;
	}
	LL ans = f[n];
	LL ansa = 1, ansb = 1, ansp = 1;
	for(auto p : mpa) ansa = ansa * f[p.second] % mod;
	for(auto p : mpb) ansb = ansb * f[p.second] % mod;
	ans = (ans - ansa - ansb + mod + mod) % mod;
	for(auto p : mpp) ansp = ansp * f[p.second] % mod;
	int x = 0;
	for(auto p : mpp){
		if(p.first.second < x) no(ans);
		x = p.first.second;
	}
	cout << (ans + ansp) % mod;
	return 0;
}