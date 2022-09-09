//Author: Heltion
//Date: 10-16-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 100000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		if(a[i] % 2) cnt += 1;
	}
	cnt /= 2;
	for(int i = 1; i <= n; i += 1){
		if(a[i] % 2 == 0) cout << a[i] / 2 << "\n";
		else{
			if(a[i] > 0) a[i] = a[i] / 2;
			else a[i] = a[i] / 2 - 1;
			if(cnt > 0) cout << a[i] + 1 << "\n";
			else cout << a[i] << "\n";
			cnt -= 1;
		}
	}
	return 0;
}