#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> g[N];
int a[N], b[N], in[N], used[N], take[N], cyc[N];

void print(int n){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == b[i])ans++;
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i++){
		cout << b[i] << " ";
	}
	cout << '\n';
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		g[i].clear();
		in[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		in[a[i]]++;
		g[a[i]].emplace_back(i);
		used[i] = cyc[i] = take[i] = -1;
	}
	for(int i = 1; i <= n; i++){
		if(cyc[i] != -1)continue;
		int x = i;
		int c = -1;
		set<int> st;
		while(true){
			if(st.count(x)){
				c = x;
				break;
			}
			if(cyc[x] != -1){
				break;
			}
			st.insert(x);
			cyc[x] = 0;
			x = a[x];
		}
		if(c == -1)continue;
		x = c;
		while(true){
			cyc[x] = 1;
			x = a[x];
			if(x == c)break;
		}
	}
	for(int i = 1; i <= n; i++){
		if(g[i].empty())continue;
		if(g[i].size() == 1){
			b[g[i][0]] = i;
			used[g[i][0]] = take[i] = 1;
			continue;
		}
		bool flg = false;
		for(int x : g[i]){
			if(cyc[x])continue;
			
			b[x] = i;
			used[x] = take[i] = 1;
			flg = true; break;
		}
		if(!flg){
			b[g[i][0]] = i;
			used[g[i][0]] = take[i] = 1;
		}
	}
	set<int> st1, st2;
	for(int i = 1; i <= n; i++){
		if(used[i] == -1)st1.insert(i);
		if(take[i] == -1)st2.insert(i);
	}
	if(st1.empty()){
		print(n);
		return;
	}
	if(st1.size() == 1){
		int x = *st1.begin();
		int y = *st2.begin();
		assert(x != y);
		b[x] = y;
		print(n);
		return;
	}
	while(st1.size() > 2){
		int x = *st1.begin(); st1.erase(x);
		if((*st2.begin()) != x){
			int y = *st2.begin(); st2.erase(y);
			b[x] = y;
		}else{
			int y = *st2.rbegin(); st2.erase(y);
			b[x] = y;
		}
	}
	int x1 = *st1.begin();
	int y1 = *st2.begin();
	int x2 = *st1.rbegin();
	int y2 = *st2.rbegin();
	if(x1 == y1 || x2 == y2){
		b[x1] = y2;
		b[x2] = y1;
	}else{
		b[x1] = y1;
		b[x2] = y2;
	}
	print(n);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}