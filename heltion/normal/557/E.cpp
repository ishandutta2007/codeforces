#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 5400;
constexpr int maxm = 15000000;
char s[maxn];
vector<int> v[maxn];
int a[maxn], t[maxm][2], tn = 1, cnt[maxm], n, k;
string ans;
void insert(int l){
	sort(v[l].begin(), v[l].end());
	int p = 1;
	for(int r = l, q = 0; r <= n and q < v[l].size(); p = t[p][a[r]], r += 1){
		if(not t[p][a[r]]) t[p][a[r]] = tn += 1;
		if(r == v[l][q]){
			cnt[t[p][a[r]]] += 1; 
			q += 1;
		}
	}
}
void DFS(int p){
	if(0 < k and k <= cnt[p]) cout << ans;
	k -= cnt[p];
	if(t[p][0]){
		ans.push_back('a');
		DFS(t[p][0]);
		ans.pop_back();
	}
	if(t[p][1]){
		ans.push_back('b');
		DFS(t[p][1]);
		ans.pop_back();
	}
}
int main(){
	//freopen("557E.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> (s + 1) >> k;
	n = strlen(s + 1);
	for(int i = 1; i <= n; i += 1) a[i] = s[i] - 'a';
	for(int i = 1; i <= n; i += 1){
		for(int l = i, r = i + 1; 1 <= l and r <= n and a[l] == a[r]; l -= 2, r += 2)
			v[l].push_back(r);
		for(int l = i - 1, r = i + 2; 1 <= l and r <= n and a[l] == a[r]; l -= 2, r += 2)
			v[l].push_back(r);
		for(int l = i, r = i; 1 <= l and r <= n and a[l] == a[r]; l -= 2, r += 2)
			v[l].push_back(r);
		for(int l = i - 1, r = i + 1; 1 <= l and r <= n and a[l] == a[r]; l -= 2, r += 2)
			v[l].push_back(r);
	}
	for(int i = 1; i <= n; i += 1) insert(i);
	DFS(1);
}