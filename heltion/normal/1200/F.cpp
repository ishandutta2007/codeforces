//Author: Heltion
//Date: 08-12-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1200;
constexpr int mod = 2520;
int k[maxn];
vector<int> G[maxn];
int ans[3000000];
int query(int x, int y){
	int p = x * mod + y;
	if(ans[p]) return ans[p];
	stack<int> st;
	set<int> se;
	st.push(p);
	se.insert(p);
	while(true){
		int x = p / mod, y = p % mod;
		int ny = ((y + k[x]) % mod + mod) % mod;
		int nx = G[x][ny % G[x].size()];
		int np = nx * mod + ny;
		if(ans[np]){
			while(not st.empty()){
				ans[st.top()] = ans[np];
				st.pop();
			}
			return ans[np];
		}
		if(se.count(np)){
			set<int> sp;
			while(true){
				int pp = st.top();
				sp.insert(pp / mod);
				st.pop();
				if(pp == np) break;
			}
			for(int x : se) ans[x] = sp.size();
			return sp.size();
		}
		p = np;
		st.push(p);
		se.insert(p);
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> k[i];
	for(int i = 1, m; i <= n; i += 1){
		cin >> m;
		for(int j = 0, v; j < m; j += 1){
			cin >> v;
			G[i].push_back(v);
		}
	}
	int q;
	for(cin >> q; q; q -= 1){
		int x, y;
		cin >> x >> y;
		y = (y % mod + mod) % mod;
		cout << query(x, y) << "\n";
	}
	return 0;
}