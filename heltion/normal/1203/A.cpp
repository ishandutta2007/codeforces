//Author: Heltion
//Date: 08-13-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 200;
int p[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		int n;
		cin >> n;
		for(int i = 0; i < n; i += 1) cin >> p[i];
		for(int i = 0; i < n; i += 1) if(p[i] == 1){
			if(n == 1) cout << "YES\n";
			else if(p[(i + 1) % n] == 2){
				int x = i, t = 1, ok = 1;
				while(t < n){
					x = (x + 1) % n;
					t += 1;
					if(p[x] != t) ok = 0;
				}
				cout << (ok ? "YES\n" : "NO\n");
			}
			else if(p[(i + n - 1) % n] == 2){
				int x = i, t = 1, ok = 1;
				while(t < n){
					x = (x + n - 1) % n;
					t += 1;
					if(p[x] != t) ok = 0;
				}
				cout << (ok ? "YES\n" : "NO\n");
			}
			else cout << "NO\n";
		}
	}
	return 0;
}