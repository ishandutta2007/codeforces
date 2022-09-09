//Author: Heltion
//Date: 08-07-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1200000;
constexpr LL base = 307, mod = 360023843327831ll;
char s[maxn], t[maxn];
LL ht[maxn], st[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, sn = 0, tn;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> (t + 1);
		tn = strlen(t + 1);
		for(int i = 1; i <= tn; i += 1) ht[i] = (ht[i - 1] * base + t[i]) % mod;
		for(LL i = 1, pw = 1; i <= min(sn, tn); i += 1){
			st[i] = (st[i - 1] + pw * s[sn - i + 1]) % mod;
			pw = pw * base % mod;
		}
		int x = 0;
		for(int i = 1; i <= min(sn, tn); i += 1) if(ht[i] == st[i]) x = i;
		for(int i = x + 1; i <= tn; i += 1) s[sn + i - x] = t[i];
		sn += tn - x;
	}
	cout << (s + 1);
	return 0;
}