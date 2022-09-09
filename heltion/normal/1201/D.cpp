//Author: Heltion
//Date: 08-05-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 200000;
pair<int, int> p[maxn];
int b[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for(int i = 0; i < k; i += 1) cin >> p[i].first >> p[i].second;
	for(int i = 0; i < q; i += 1) cin >> b[i];
	sort(b, b + q);
	sort(p, p + k);
	int pos[2] = {1, 1}, r = 1;
	LL f[2] = {0, 0};
	for(int i = 0, j = 0; i < k; i = j){
		while(j < k and p[j].first == p[i].first) j += 1;
		if(p[i].first == 1){
			pos[0] = p[i].second;
			pos[1] = p[j - 1].second;
			for(int t = 0; t < 2; t += 1) f[t] = abs(1 - pos[t ^ 1]) + abs(pos[t ^ 1] - pos[t]);
			continue;
		}
		int npos[2] = {p[i].second, p[j - 1].second}, nr = p[i].first;
		LL nf[2] = {(LL)1e18, (LL)1e18};

		for(int s = 0; s < 2; s += 1)
			for(int t = 0; t < 2; t += 1){
				LL x = lower_bound(b, b + q, pos[s]) - b;
				if(x < q) nf[t] = min(nf[t], f[s] + abs(pos[s] - b[x]) + abs(r - nr)
					+ abs(b[x] - npos[t ^ 1]) + abs(npos[t ^ 1] - npos[t]));
				x -= 1;
				if(~x) nf[t] = min(nf[t], f[s] + abs(pos[s] - b[x]) + abs(r - nr)
					+ abs(b[x] - npos[t ^ 1]) + abs(npos[t ^ 1] - npos[t]));
			}
		for(int t = 0; t < 2; t += 1){
			f[t] = nf[t];
			pos[t] = npos[t];
		}
		r = nr;
	}
	cout << min(f[0], f[1]);
	return 0;
}