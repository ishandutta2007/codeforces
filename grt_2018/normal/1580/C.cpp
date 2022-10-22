#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10, B = 500;
int n, m;
pi p[nax];
int cnt[nax];
int res[B + 10][B + 10];
int last[nax];

int main() {_
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i].ST >> p[i].ND;
	}
	int all = 0, ile = 0;
	for(int i = 1; i <= m; ++i) {
		int type, x;
		cin >> type >> x;
		int delta = (type == 1 ? 1 : -1);
		ile += delta;
		if(delta == 1) {
			last[x] = i;
		}
		if(p[x].ST + p[x].ND <= B) {
			for(int r = 0; r < p[x].ST; ++r) {
				res[p[x].ST + p[x].ND][(r + last[x]) % (p[x].ST + p[x].ND)] += delta;
			}
		} else {
			for(int l = last[x]; l <= m; l += p[x].ST + p[x].ND) {
				cnt[l] += delta;
				if(l + p[x].ST <= m) {
					cnt[p[x].ST + l] -= delta;
				}
				if(l < i) {
					all += delta;
				}
				if(l + p[x].ST < i) {
					all -= delta;
				}
			}
		}
		all += cnt[i];
		int sum = 0;
		for(int j = 1; j <= B; ++j) {
			sum += res[j][i % j];
		}
		//cout << all << " " << sum << " ";
		cout << ile - (all + sum) << "\n";
	}
	
	
}