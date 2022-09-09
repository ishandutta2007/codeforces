//Author: Heltion
//Date: 08-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
int p[maxn], q[maxn], p_[maxn], t[maxn], s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i += 1){
		cin >> p[i];
		p_[p[i]] = i;
	}
	for(int i = 1; i <= n; i += 1) cin >> q[i];
	for(int i = 1; i < n; i += 1)
		if(p_[q[i]] > p_[q[i + 1]]){
			t[p_[q[i + 1]]] += 1;
			t[p_[q[i]]] -= 1;
		}
	for(int i = 1; i <= n; i += 1) t[i] += t[i - 1];
	int x = 0;
	for(int i = 1; i <= n; i += 1){
		if(not s[p[i]]) s[p[i]] = x += 1;
		if(t[i]) s[p[i + 1]] = s[p[i]];
	}
	if(x < k) no();
	cout << "YES\n";
	for(int i = 1; i <= n; i += 1) cout << (char)('a' + min(s[i], 26) - 1);
	return 0;
}