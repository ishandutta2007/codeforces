#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n;
int a[maxn], t[maxn];
vector<pi> s; 
int main() { 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]), 
		s.pb(mp(a[i], t[i]));
	sort(s.begin(), s.end());
	ll ans = 0;
	for (int i = 0; i < n; ) {
		int j = i + 1;
		while (j < n && s[j].fi < s[i].fi + (j - i)) j++;
		int l = s[i].fi, r = s[i].fi + (j - i) - 1;
		for (int k = i; k < j; k++)
			ans -= 1ll * s[k].fi * s[k].se;
		priority_queue<int> g; 
		int pl = i;
		for (int i = l; i <= r; i++) {
			while (pl < j && s[pl].fi == i)
				g.push(s[pl].se), pl++;
			ans += 1ll * i * g.top();
			g.pop();
		}
		i = j;
	}
	cout << ans << endl;
	return 0;
}