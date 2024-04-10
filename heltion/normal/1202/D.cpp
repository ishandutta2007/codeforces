//Author: Heltion
//Date: 08-07-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 40000;
LL a[maxn];
int v[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	for(LL i = 1; i < maxn; i += 1) a[i] = i * (i - 1) / 2;
	int T;
	for(cin >> T; T; T -= 1){
		LL n;
		cin >> n;
		int tn = 0;
		for(int i = maxn - 1; i and n; i -= 1)
			while(n >= a[i]){
				n -= a[i];
				v[tn += 1] = i;
			}
		v[tn + 1] = 0;
		for(int i = 1; i <= tn; i += 1){
			cout << "1";
			for(int j = 0; j < v[i] - v[i + 1]; j += 1) cout << "3";
		}
		cout << "7\n";
	}
	return 0;
}