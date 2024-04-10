//Author: Heltion
//Date: 08-13-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 400;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		int n;
		cin >> n;
		for(int i = 0; i < n * 4; i += 1) cin >> a[i];
		sort(a, a + n * 4);
		int ok = 1, s = 0;
		int L = 0, R = n * 4 - 1;
		while(L < R){
			if(a[L] != a[L + 1] or a[R] != a[R - 1]) ok = 0;
			if(s == 0) s = a[L] * a[R];
			else if(s != a[L] * a[R]) ok = 0;
			L += 2;
			R -= 2;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}