#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
LL a[maxn], s[maxn];
set<pair<LL, int> > st;
set<pair<LL, int>, greater<pair<LL, int>>> st2;
int main(){
	int n;
	LL ans = 0, pans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1){
		scanf("%lld", a + i);
		s[i] = s[i - 1] + a[i];
		ans += a[i] * i;
	}
	st.insert(make_pair((LL)1E9, n));
	for(int i = n - 1; i >= 1; i -= 1){
		auto it = st.upper_bound(make_pair(a[i], 0));
		pans = max(pans, (a[i] * it->second - s[it->second]) + (s[i] - a[i] * i));
		LL p = 0;
		for(it = st.begin(); it != st.end(); it = st.erase(it)){
			p = (s[it->second] - s[i]) / (it->second - i);
			if(p < it->first) break;
		}
		st.insert(make_pair(p, i));
	}
	st2.insert(make_pair((LL)-1E9, 1));
	for(int i = 2; i <= n; i += 1){
		auto it = st2.lower_bound(make_pair(a[i], n));
		pans = max(pans, (a[i] * it->second - s[it->second - 1]) + (s[i - 1] - a[i] * i));
		LL p = 0;
		for(it = st2.begin(); it != st2.end(); it = st2.erase(it)){
			p = (s[i - 1] - s[it->second - 1] + i - it->second - 1) / (i - it->second);
			if(p > it->first) break;
		}
		st2.insert(make_pair(p, i));
	}
	printf("%lld", ans + pans);
}