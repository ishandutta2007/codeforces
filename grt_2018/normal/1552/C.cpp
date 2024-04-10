#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 210;
int t, n, k;
pi edge[nax];
bool used[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int a, b, i = 0; i < k; ++i) {
			cin >> a >> b;
			edge[i] = {a, b};
			used[a] = used[b] = true;
		}
		vi ver = {};
		for(int i = 1; i <= 2 * n; ++i) {
			if(!used[i]) ver.PB(i);
		}
		for(int i = 0; i < (n - k); ++i) {
			edge[i + k] = {ver[i], ver[i + n - k]};
		}
		for(int i = 0; i < n; ++i) {
			if(edge[i].ST > edge[i].ND) swap(edge[i].ST, edge[i].ND);
		}
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if(((edge[j].ST < edge[i].ST && edge[i].ST < edge[j].ND) || (edge[j].ST < edge[i].ND && edge[i].ND < edge[j].ND))&&((edge[i].ST < edge[j].ST && edge[j].ST < edge[i].ND) || (edge[i].ST < edge[j].ND && edge[j].ND < edge[i].ND))) {
					ans++;
				}
			}
		}
		for(int i = 1; i <= 2 * n; ++i) used[i] = false;
		cout << ans << "\n";
	}
}