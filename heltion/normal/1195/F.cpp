//Author: Heltion
//Date: 07-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 320000;
void no(){cout << "NO"; exit(0);}
LL gcd(LL a, LL b){
	a = abs(a);
	b = abs(b);
	return b ? gcd(b, a % b) : a;
}
pair<LL, LL> norm(pair<LL, LL> p){
	LL d = gcd(p.first, p.second);
	return make_pair(p.first / d, p.second / d);
}
map<pair<LL, LL>, int> mp;
int s[maxn], c[maxn], x[maxn], y[maxn];
int p[maxn], pos[maxn];
struct Q{
	int l, r, id;
	bool operator < (const Q & b){
		return r < b.r;
	}
}que[maxn];
LL t[maxn];
void add(int x, int n, int v){
	for(; x <= n; x += x & -x) t[x] += v;
}
int sum(int x){
	int res = 0;
	for(; x; x -= x & -x) res += t[x];
	return res;
}
int ans[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		int k;
		cin >> k;
		s[i] = s[i - 1] + k;
		for(int j = 0; j < k; j += 1) cin >> x[j] >> y[j];
		x[k] = x[0];
		y[k] = y[0];
		for(int j = 0; j < k; j += 1){
			auto p = norm(make_pair(x[j + 1] - x[j], y[j + 1] - y[j]));
			if(not mp.count(p)) {
				int x = mp.size() + 1;
				mp[p] = x;
			}
			c[s[i - 1] + j + 1] = mp[p];
		}
	}
	//for(int i = 1; i <= s[n]; i += 1){
	//	cout << i << " " << c[i] << endl;
	//}
	int q;
	cin >> q;
	for(int i = 0; i < q; i += 1){
		que[i].id = i;
		cin >> que[i].l >>  que[i].r;
		que[i].l = s[que[i].l - 1] + 1;
		que[i].r = s[que[i].r];
	}
	sort(que, que + q);
	for(int i = 1; i <= s[n]; i += 1){
		p[i] = pos[c[i]];
		pos[c[i]] = i;
	}
	int r = 0;
	for(int i = 0; i < q; i += 1){
		while(r < que[i].r){
			r += 1;
			if(p[r]) add(p[r], s[n], -1);
			add(r, s[n], 1);
		}
		ans[que[i].id] = sum(que[i].r) - sum(que[i].l - 1);
		//cout << que[i].l << " " << que[i].r << " " << ans[que[i].id] << endl;
	}
	for(int i = 0; i < q; i += 1) cout << ans[i] << "\n";
	return 0;
}