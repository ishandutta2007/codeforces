//Author: Heltion
//Date: 2019-05-09
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 120000;
int c[maxn], u[maxn];
multiset<int> ms;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> u[i];
	for(int i = 1; i <= n; i += 1){
		if(c[u[i]]) ms.erase(ms.find(c[u[i]]));
		ms.insert(c[u[i]] += 1);
		if(ms.size() == 1) ans = i;
		if(*ms.begin() == 1 and *ms.rbegin() * (ms.size() - 1) + 1 == i) ans = i;
		if(*ms.rbegin() - *ms.begin() == 1 and *ms.begin() * ms.size() + 1 == i) ans = i;
	}
	cout << ans;
	return 0;
}