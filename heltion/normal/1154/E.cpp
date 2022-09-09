#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(const char *s = "NO"){cout << s;exit(0);} 
constexpr int maxn = 240000;
int a[maxn], p[maxn], l[maxn], r[maxn];
set<int, greater<int>> s;
char ans[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, k, t = 1;
	cin >> n >> k;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		p[a[i]] = i;
		s.insert(i);
		l[i] = i - 1;
		r[i] = i + 1;
	}
	for(; not s.empty(); t = 3 - t){
		int u = *s.begin(), L = l[p[u]], R = r[p[u]];
		for(int j = 0; R <= n and j < k; R = r[R], j += 1){
			s.erase(a[R]);
			ans[R] = t + '0';
		}
		for(int j = 0; L and j < k; L = l[L], j += 1){
			s.erase(a[L]);
			ans[L] = t + '0';
		}
		s.erase(u);
		ans[p[u]] = t + '0';
		l[R] = L;
		r[L] = R;
	}
	cout << (ans + 1);
}