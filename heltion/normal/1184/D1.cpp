//Author: Heltion
//Date: 07-31-2019
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
	int n, k, m, t;
	cin >> n >> k >> m >> t;
	for(int i = 1; i <= t; i += 1){
		int t, p;
		cin >> t >> p;
		if(t == 0){
			if(p >= k) n = p;
			else n -= p, k -= p;
		}
		else{
			if(p > k) n += 1;
			else n += 1, k += 1;
		}
		cout << n << " " << k << "\n";
	}
	return 0;
}