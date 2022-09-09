//Author: Heltion
//Date: 10-08-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
int p[maxn], d[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		int h, n;
		cin >> h >> n;
		for(int i = 1; i <= n; i += 1) cin >> p[i];
		p[n + 1] = d[n + 1] = d[n] = 0;
		for(int i = n - 1; i >= 1; i -= 1){
			d[i] = h;
			if(i + 1 <= n and p[i + 1]  == p[i + 2] + 1) d[i] = min(d[i], d[i + 2]);
			d[i] = min(d[i], d[i + 1] + 1);
		}
		cout << d[1] << "\n";
	}
	return 0;
}