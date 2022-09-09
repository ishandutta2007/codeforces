//Author: Heltion
//Date: 08-05-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 100000;
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	sort(a, a + n);
	LL sum = 0;
	for(int i = 0; i + 1 < n; i += 1) sum += a[i];
	if(sum < a[n - 1] or (sum + a[n - 1]) % 2) cout << "NO";
	else cout << "YES";	
	return 0;
}