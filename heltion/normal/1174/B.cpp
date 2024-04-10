//Author: Heltion
//Date: 2019-06-03
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s){cout << s; exit(0);}
constexpr int maxn = 120000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	for(int i = 1; i < n; i += 1)
		if((a[i] + a[i - 1]) & 1){
			sort(a, a + n);
			break;
		}
	for(int i = 0; i < n; i += 1) cout << a[i] << " ";
	return 0;
}