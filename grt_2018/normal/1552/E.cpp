#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 110;
int n, k;
int cnt[nax];
bool done[nax];
int last[nax], last2[nax];
pi ans[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int op = 0;
	int l = (n - 1) / (k - 1) + 1;
	vi used = {};
	for(int i = 0; i < n * k; ++i) {
		int x;
		cin >> x;
		cnt[x]++;
		last2[x] = last[x];
		last[x] = i + 1;
		if(cnt[x] == 2 && !done[x]) {
			op++;
			used.PB(x);
		}
		if(op == l || i == n * k - 1) {
			op = 0;
			for(int y : used) {
				ans[y] = {last2[y], last[y]};
				done[y] = true;
			}
			used.clear();
			for(int j = 1; j <= n; ++j) {
				cnt[j] = 0;
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		auto x = ans[i];
		cout << x.ST << " " << x.ND << "\n";
	}
	
	
}