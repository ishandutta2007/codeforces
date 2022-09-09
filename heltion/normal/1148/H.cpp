#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
struct rec{
	int x1, x2, y1, y2;
	LL s = 0;
};
int a[maxn], L[maxn], R[maxn], T[maxn], p[maxn];
vector<rec> v[maxn];
void remove(int x, int t){
	LL s = 0;
	if(not v[x].empty()) s = v[x].back().s;
	if(t > T[x]) v[x].push_back({T[x], t - 1, L[x], R[x], s + 1LL * (R[x] - L[x] + 1) * (t - T[x])});
	T[x] = 0;
}
void add(int x, int xL, int xR, int t){
	if(T[x]) remove(x, t);
	else L[x] = xL;
	R[x] = xR;
	T[x] = t;
}
LL query(int k, int kL, int kR, int t){
	LL res = 0;
	int bL, bR, bM;
	if(not v[k].empty()){
		int L, R;
		for(bL = 0, bR = v[k].size() - 1; bL < bR;){
			bM = (bL + bR) >> 1;
			if(v[k][bM].x2 < kL or v[k][bM].y2 < kL) bL = bM + 1;
			else bR = bM;
		}
		L = bL;
		for(bL = 0, bR = v[k].size() - 1; bL < bR;){
			bM = (bL + bR + 1) >> 1;
			if(v[k][bM].x1 > kR or v[k][bM].y1 > kR) bR = bM - 1;
			else bL = bM;
		}
		R = bL;
		if(L <= R and v[k][L].x2 >= kL and v[k][L].y2 >= kL and v[k][R].x1 <= kR and v[k][R].y1 <= kR){
			res += v[k][R].s - (L ? v[k][L - 1].s : 0);
			if(kL > v[k][L].x1) res -= 1LL * (v[k][L].y2 - v[k][L].y1 + 1) * (kL - v[k][L].x1);
			if(kR < v[k][R].x2) res -= 1LL * (v[k][R].y2 - v[k][R].y1 + 1) * (v[k][R].x2 - kR);
			if(v[k][L].y1 < kL){
				for(bL = L, bR = v[k].size() - 1; bL < bR;){
					bM = (bL + bR + 1) >> 1;
					if(v[k][bM].y1 < kL) bL = bM;
					else bR = bM - 1;
				}
				res -= 1LL * (kL - v[k][L].y1) * (min(v[k][bL].x2, kR) - max(v[k][L].x1, kL) + 1);
			}
		}
	}
	if(T[k]){
		int x1 = max(kL, T[k]);
		int x2 = min(kR, t);
		int y1 = max(kL, L[k]);
		int y2 = min(kR, R[k]);
		if(x1 <= x2 and y1 <= y2) res += 1LL * (x2 - x1 + 1) * (y2 - y1 + 1);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	LL lans = 0;
	for(int i = 1; i <= n; i += 1){
		int l, r, k;
		cin >> a[i] >> l >> r >> k;
		a[i] = (a[i] + lans) % (n + 1);
		l = (l + lans) % i + 1;
		r = (r + lans) % i + 1;
		if(l > r) swap(l, r);
		k = (k + lans) % (n + 1);
		if(T[a[i]]){
			int RR = R[a[i]];
			for(int x = a[i] + 1; ; x += 1)
				if(p[x] < L[a[i]]){
					add(x, L[a[i]], RR, i);
					break;
				}
				else if(p[x] + 1 <= RR){
					add(x, p[x] + 1, RR, i);
					RR = p[x];
				}
			remove(a[i], i);
		}
		add(!a[i], i, i, i);
		p[a[i]] = i;
		cout << (lans = query(k, l, r, i)) << "\n";
	}
}