#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
set<pii> v[10];
#define maxn 1200
bool T[maxn][maxn];
char s[maxn];
int ans[10];
int sd[10];
set<pii> add, rem;
bool ch(int i, int x, int y){
	if(T[x][y] == false) return false;
	//cout << i << " " << x << " " << y << endl;
	T[x][y] = false;
	ans[i] += 1;
	add.insert(make_pair(x, y));
	return true;
}
bool ex(int i){
	bool aok = false;
	for(int sss = 0; sss < sd[i]; sss += 1){
		bool ok = false;
		add.clear();
		rem.clear();
		for(auto p : v[i]){
			bool pok = false;
			if(ch(i, p.first + 1, p.second)) pok = true;
			if(ch(i, p.first - 1, p.second)) pok = true;
			if(ch(i, p.first, p.second + 1)) pok = true;
			if(ch(i, p.first, p.second - 1)) pok = true;
			if(pok) ok = true;
			else rem.insert(make_pair(p.first, p.second));
		}
		for(auto p : add) v[i].insert(p);
		for(auto p : rem) v[i].erase(p);
		if(ok == false) break;
		aok = true;
	}
	return aok;
}
int main(){
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= q; i += 1) cin >> sd[i];
	for(int i = 1; i <= n; i += 1){
		cin >> s + 1;
		for(int j = 1; j <= m; j += 1){
			if(s[j] == '#')  continue;
			if(s[j] == '.') T[i][j] = true;
			else{
				ans[s[j] - '0'] += 1;
				v[s[j] - '0'].insert(make_pair(i, j));
			}
		}
	}
	while(true){
		bool ok = false;
		for(int i = 1; i <= q; i += 1) if(ex(i)) ok = true;
		if(ok == false) break;
	}
	for(int i = 1; i <= q; i += 1) cout << ans[i] << " "; 
}