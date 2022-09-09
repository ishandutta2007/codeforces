//Author: Heltion
//Date: 08-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
struct edge{
	int u, v, w;
	bool operator < (const edge& b){
		return w < b.w;
	}
}e[maxn];
int pa[maxn];
LL sum = 0;
map<int, LL> mp;
int gpa(int u){
	return pa[u] < 0 ? u : pa[u] = gpa(pa[u]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i < n; i += 1) cin >> e[i].u >> e[i].v >> e[i].w;
	for(int i = 1; i <= n; i += 1) pa[i] = -1;
	sort(e + 1, e + n);
	for(int i = 1; i < n; i += 1){
		int u = gpa(e[i].u), v = gpa(e[i].v);
		if(u != v){
			sum += 1LL * pa[u] * pa[v];
			pa[v] += pa[u];
			pa[u] = v;
		}
		mp[e[i].w] = sum;
	}
	for(int i = 1; i <= m; i += 1){
		int q;
		cin >> q;
		auto it = mp.upper_bound(q);
		if(it == mp.begin()) cout << "0 ";
		else{
			it--;
			cout << it->second << " ";
		}
	}
	return 0;
}