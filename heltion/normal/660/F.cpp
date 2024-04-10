#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
LL a[maxn], s[maxn], ss[maxn];
set<pair<LL, int> > f;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1){
		scanf("%lld", a + i);
		s[i] = s[i - 1] + a[i];
		ss[i] = ss[i - 1] + a[i] * i;
	}
	f.insert(make_pair((LL)1E9, 0));
	LL ans = 0;
	for(int i = 1; i <= n; i += 1){
		auto it = f.upper_bound(make_pair(s[i], -1));
		ans = max(ans, ss[i] - ss[it->second] - (s[i] - s[it->second]) * it->second);
		LL x = 0;
		for(it = f.begin(); it != f.end(); it = f.erase(it)){
			x = ((s[i] * i - ss[i]) - (s[it->second] * it->second - ss[it->second])) / (i - it->second);
			if(x < it->first) break;
		}
		f.insert(make_pair(x, i));
	}
	printf("%lld", ans);
}