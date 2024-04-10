#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 6000;
set<int> s;
int p[maxn], c[maxn], dd[maxn], ans[maxn];
vector<int> g[maxn];
int f[maxn], b[maxn];
bool find(int x){
	for(int v : g[x]) if(!~b[v]){
		b[v] = 0;
		if(!~f[v] || find(f[v])) return f[v] = x, 1;
	}
	return 0;
}
int main(){
	int n, m, d;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1) cin >> p[i];
	for(int i = 1; i <= n; i += 1) cin >> c[i];
	for(int i = 1; i <= n; i += 1) s.insert(i);
	cin >> d;
	for(int i = 1; i <= d; i += 1){
		cin >> dd[i];
		s.erase(dd[i]);
	}
	for(int i = d + 1; i <= n; i += 1){
		dd[i] = *s.begin();
		s.erase(dd[i]);
	}
	for(int i = 1; i <= m; i += 1) f[i] = -1;
	for(int i = n; i >= 1; i -= 1){
		ans[i] = ans[i + 1];
		g[p[dd[i]]].push_back(c[dd[i]]);
		while(true){
			for(int i = 1; i <= m; i += 1) b[i] = -1;
			if(not find(ans[i])) break;
			ans[i] += 1;
		}
		//for(int i = 1; i <= m; i += 1) cout << f[i] << " ";
		//cout << endl;
	}
	for(int i = 2; i <= d + 1; i += 1) cout << ans[i] << endl;
}