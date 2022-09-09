#include<bits/stdc++.h>
using namespace std;
#define maxn 240000
int a[maxn], s[maxn];
map<int, int> mp;
typedef long long LL;
const LL mod = 998244353;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		cin >> a[i];
		if(mp.count(a[i])){
			s[mp[a[i]]] += 1;
			s[i] -= 1;
		}
		mp[a[i]] = i; 
	}
	LL ans = 1; 
	for(int i = 1; i < n; i += 1){
		assert(s[0] >= 0);
		if(s[0] == 0) ans = ans * 2 % mod;
		s[0] += s[i];
	}
	cout << ans;
}