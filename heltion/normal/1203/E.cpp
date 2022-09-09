//Author: Heltion
//Date: 08-13-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 150000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, ans = 0, pre = 0;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i += 1){
		if(a[i] - 1 > pre){
			pre = a[i] - 1;
			ans += 1;
		}
		else if(a[i] > pre){
			pre = a[i];
			ans += 1;
		}
		else if(a[i] + 1 > pre){
			pre = a[i] + 1;
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}