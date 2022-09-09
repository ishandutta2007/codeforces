//Author: Heltion
//Date: 08-07-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
char x[maxn], y[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	for(cin >> T; T; T -= 1){
		cin >> x >> y;
		int n = strlen(x), m = strlen(y), q = m - 1;
		while(y[q] == '0') q -= 1;
		q += n - m;
		int p = q;
		while(x[p] == '0') p -= 1;
		cout << q - p << "\n";
	}
	return 0;
}