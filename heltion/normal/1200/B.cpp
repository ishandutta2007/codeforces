//Author: Heltion
//Date: 08-12-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1200000;
int h[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int t;
	for(cin >> t; t; t -= 1){
		int n, m, k;
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i += 1) cin >> h[i];
		bool ok = true;
		for(int i = 1; i < n; i += 1){
			if(h[i] < max(0, h[i + 1] - k)){
				if(h[i] + m < max(0, h[i + 1] - k)){
					ok = false;
					break;
				}
				m -= max(0, h[i + 1] - k) - h[i];
			}
			else{
				m += h[i] - max(0, h[i + 1] - k);
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}	
	return 0;
}