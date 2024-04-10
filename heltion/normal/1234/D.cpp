#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
char s[maxn];
int sum[26][maxn];
void add(int k, int p, int x){
	for(; p < maxn; p += p & -p) sum[k][p] += x; 
}
int query(int k, int p){
	int res = 0;
	for(; p; p -= p & -p) res += sum[k][p];
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	int n, q;
	cin >> (s + 1) >> q;
	n = strlen(s + 1);
	for(int i = 1; i <= n; i += 1) add(s[i] - 'a', i, 1);
	for(; q; q -= 1){
		int t;
		cin >> t;
		if(t == 1){
			int pos;
			string c;
			cin >> pos >> c;
			add(s[pos] - 'a', pos, -1);
			s[pos] = c[0];
			add(s[pos] - 'a', pos, 1);
		}
		else{
			int l, r, ans = 0;
			cin >> l >> r;
			for(int i = 0; i < 26; i += 1){
				ans += not not(query(i, r) - query(i, l - 1));
			}
			cout << ans << "\n";
		}
	}
}