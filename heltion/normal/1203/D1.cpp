//Author: Heltion
//Date: 08-13-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
char s[maxn], t[maxn];
int pre[maxn], suf[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	cin >> (s + 1) >> (t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	for(int i = 1, j = 1; i <= m; i += 1){
		while(s[j] != t[i]) j += 1;
		pre[i] = j ++;
	}
	for(int i = m, j = n; i; i -= 1){
		while(s[j] != t[i]) j -= 1;
		suf[i] = j --;
	}
	suf[m + 1] = n + 1;
	int ans = 0;
	for(int i = 0; i <= m; i += 1) ans = max(ans, suf[i + 1] - pre[i] - 1);
	cout << ans;
	return 0;
}