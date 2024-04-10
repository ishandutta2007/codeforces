#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 240000;
char s[maxn], t[maxn];
int ss[maxn], tt[maxn], rr[maxn];
int main(){
	ios::sync_with_stdio(false);
	int k;
	cin >> k >> s >> t;
	for(int i = 0; i < k; i += 1) ss[i] = s[i] - 'a';
	for(int i = 0; i < k; i += 1) tt[i] = t[i] - 'a';
	for(int i = 0; i < k; i += 1) rr[i] = ss[i] + tt[i];
	for(int i = k - 1; i; i -= 1) {
		rr[i - 1] += rr[i] / 26;
		rr[i] %= 26;
	}
	for(int i = 0; i < k; i += 1){
		rr[i + 1] += 26 * (rr[i] & 1);
		rr[i] /= 2;
	}
	for(int i = 0; i < k; i += 1) cout << (char)(rr[i] + 'a');
}