#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using pii = pair<int, int>;
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 200000;
map<pii, int> mp;
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
int a[maxn], b[maxn];
int main(){
	int n, s = 0, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1) scanf("%d", a + i);
	for(int i = 0; i < n; i += 1) scanf("%d", b + i);
	for(int i = 0; i < n; i += 1){
		if(b[i] == 0 and a[i] == 0) s += 1;
		if(a[i] != 0){
			int d = gcd(a[i], b[i]);
			a[i] /= d, b[i] /= d;
			if(a[i] < 0) a[i] = -a[i], b[i] = -b[i];
			mp[make_pair(a[i], b[i])] += 1;
		}	
	}
	for(auto p : mp) ans = max(ans, p.second);
	printf("%d", s + ans);
}