#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int maxn = 6000;
void no(){ cout << "NO"; exit(0); }
int a[maxn], s[maxn], l[maxn], r[maxn]; 
int main(){
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	int ans = 0;
	for(int i = 1; i <= q; i += 1) cin >> l[i] >> r[i];
	for(int i = 1; i <= q; i += 1){
		fill(a + 1, a + n + 1, 0);
		for(int j = 1; j <= q; j += 1) if(j != i){
			a[l[j]] += 1;
			a[r[j] + 1] -= 1;
		}
		for(int j = 1; j <= n; j += 1) a[j] += a[j - 1];
		int pans = 0;
		for(int j = 1; j <= n; j += 1){
			s[j] = s[j - 1];
			if(a[j] == 1) s[j] += 1;
			if(a[j]) pans += 1;
		}
		for(int j = i + 1; j <= q; j += 1)
			ans = max(ans, pans - s[r[j]] + s[l[j] - 1]);
	}
	cout << ans;
}