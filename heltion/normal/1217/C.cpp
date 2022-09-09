//Author: Heltion
//Date: 09-05-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
char s[maxn];
int p[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int t;
	for(cin >> t; t; t -= 1){
		cin >> (s + 1);
		int n = strlen(s + 1);
		for(int i = 1, j = 0; i <= n; i += 1){
			p[i] = j;
			if(s[i] == '1') j = i;
		}
		int ans = 0;
		for(int i = 1; i <= n; i += 1){
			if(s[i] == '1') ans += 1;
			int v = s[i] - '0', x = i;
			while(true){
				if(p[x] == 0) break;
				if(i - p[x] >= 20) break;
				v += 1 << (i - p[x]);
				if(i >= v and p[p[x]] < i - v + 1) ans += 1;
				x = p[x];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}