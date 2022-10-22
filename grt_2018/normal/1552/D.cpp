#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 15;
int t, n;
int a[nax], cnt;
bool ok;

void rec(int id, int sum) {
	if(id == n) {
		if(sum == 0 && cnt > 0) {
			ok = true;
		}
		return;
	}
	rec(id + 1, sum);
	cnt++;
	rec(id + 1, sum + a[id]);
	rec(id + 1, sum - a[id]);
	cnt--;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		ok = false;
		rec(0, 0);
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
}