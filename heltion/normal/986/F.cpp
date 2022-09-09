#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxt = 12000;
constexpr int maxk = 3.2e7;
constexpr int maxn = 1.2e5;
//https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
LL gcd(LL a, LL b, LL & x, LL & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    LL x1, y1;
    LL d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
struct query{
	LL n, k, id;
	bool operator < (const query &b){
		return k < b.k;
	}
}q[maxt];
bool vd[maxn], vp[maxk], ans[maxt];
LL d[maxn];
vector<LL> v, p;
void factorize(LL k){
	p.clear();
	for(int i = 0; k > 1 and i < (int)v.size(); i += 1)
		if(k % v[i] == 0){
			p.push_back(v[i]);
			while(k % v[i] == 0) k /= v[i];
		}
	if(k > 1) p.push_back(k);
	if(p.size() > 2){
		fill(d + 1, d + p[0], 1e18);
		fill(vd, vd + p[0], false);
		priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q;
		q.push(make_pair(d[0], 0));
		while(not q.empty()){
			int u = q.top().second;
			q.pop();
			if(vd[u]) continue;
			vd[u] = true;
			for(const int &w : p){
				int v = (u + w) % p[0];
				if(d[v] > d[u] + w) q.push(make_pair(d[v] = d[u] + w, v));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for(int i = 2; i < maxk; i += 1){
		if(not vp[i]) v.push_back(i);
		for(LL p : v){
			if(p * i >= maxk) break;
			vp[p * i] = true;
			if(i % p == 0) break;
		}
	}
	int t;
	cin >> t;
	for(int i = 0; i < t; i += 1){
		cin >> q[i].n >> q[i].k;
		q[i].id = i;
	}
	sort(q, q + t);
	for(int i = 0; i < t; i += 1){
		if(not i or q[i].k != q[i - 1].k) factorize(q[i].k);
		if(p.size() == 0) ans[q[i].id] = false;
		else if(p.size() == 1) ans[q[i].id] = q[i].n % p[0] == 0;
		else if(p.size() == 2){
			LL x, y;
			gcd(p[0], p[1], x, y);
			y = (y % p[0] + p[0]) % p[0];
			LL dr = y * (q[i].n % p[0]) % p[0] * p[1];
			ans[q[i].id] = dr <= q[i].n;
		}
		else ans[q[i].id] = d[q[i].n % p[0]] <= q[i].n;
	}
	for(int i = 0; i < t; i += 1)
		cout << (ans[i] ? "YES\n" : "NO\n");
	return 0;
}