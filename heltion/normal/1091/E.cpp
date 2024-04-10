#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


#define maxn 1200000
LL a[maxn], s[maxn];
set<int> ss;
int main(){
	ios::sync_with_stdio(false);
	int n, ans = 0, ans2;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	sort(a + 1, a + n + 1, greater<LL>());
	for(int i = 1; i <= n; i += 1) s[i] = s[i - 1] + a[i];
	LL L = 0, R = n;
	for(LL i = 1; i <= n; i += 1){
		int j = lower_bound(a + i + 1, a + n + 1, i, greater<LL>()) - a;
		LL a = s[i] - ans;
		LL b = i * (i - 1) + s[n] - s[j - 1] + (j - i - 1) * i;
		if(a > b){
			if(a - b - i > 0){
				cout << -1;
				return 0;
			}
			L = max(a - b, L);
		}
		R = min(R, j - (a - b - i));
	}
	for(int i = L; i <= R; i += 1) if((i - s[n]) % 2 == 0) ss.insert(i);
	if(ss.size() == 0) cout << -1;
	else for(int x : ss) cout << x << " ";
}