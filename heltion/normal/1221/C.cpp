//Author: Heltion
//Date: 09-19-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	cin >> q;
	for(int i = 1; i <= q; i += 1){
		int c, m, x;
		cin >> c >> m >> x;
		cout << min(c, min(m, (c + m + x) / 3)) << "\n";
	}
	return 0;
}