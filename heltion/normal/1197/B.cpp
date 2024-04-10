//Author: Heltion
//Date: 07-22-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s = "NO"){cout << s; exit(0);}
constexpr int maxn = 240000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	int p = max_element(a + 1, a + n + 1) - a;
	for(int i = 1; i <= p; i += 1) if(a[i] < a[i - 1]) no("NO");
	for(int i = p + 1; i <= n; i += 1) if(a[i] > a[i - 1]) no("NO");
	cout << "YES";
	return 0;
}