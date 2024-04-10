#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 200 * 1000 + 10;
int n;
int a[nax];
vi f[nax];
int best[2 * nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[a[i]].PB(i);
	}
	pi mx = {-1, -1};
	for(int i = 1; i <= 100; ++i) {
		mx = max(make_pair((int)f[i].size(), i), mx);
	}
	int ans = 0;
	for(int c = 1; c <= 100; ++c) {
		if(c == mx.ND) continue;
		int cur = 0;
		for(int i = 0; i <= 2 * n; ++i) best[i] = -1;
		best[n] = 0;
		//for(int x : f[c]) {
			//id++;
			//int l = 0, r = (int)f[mx.ND].size()-1, mid;
			//while(l <= r) {
				//int mid = (l + r)/2;
				//if(f[mx.ND][mid] < x) {
					//l = mid + 1;
				//} else {
					//r = mid - 1;
				//}
			//}
			//l--;
			//if(l != -1) {
				//[p, l]
				//cur += (l - p + 1);
				//p = l + 1;
				//best[id] = {max(best[id - 1].ST, cur), best[id - 1].ND};
			//}
			//cur--;
			//best[id] = {best[id].ST, min(best[id].ND, cur)};
			//l = 0
			//while(id < (int)mx.ST && f[mx.ND][id] < x) {
				//cur++;
				//if(sc.find(cur) != sc.end()) {
					//int y = sc[cur];
					
				//}
				//id++;
			//}
			//cur--;
		//}
		for(int i = 1; i <= n; ++i) {
			if(a[i] == mx.ND) {
				cur++;
			} else if(a[i] == c) {
				cur--;
			}
			if(best[cur +n] != -1) {
				ans = max(ans, i - best[cur+n]);
			} else {
				best[cur+n] = i;
			}
		}
	}
	cout << ans;
}