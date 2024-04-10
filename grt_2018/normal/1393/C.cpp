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

const int nax = 100 * 1000 + 10;
int t,n;
int a[nax], cnt[nax];
vi pos[nax];
priority_queue<pi> ag;

bool check(int xx) {
	while(!ag.empty()) ag.pop();
	for(int i = 1; i <= n; ++i) pos[i] = {};
	for(int i = 1; i <= n; ++i) if(cnt[i] > 0) {
		cnt[i]--;
		ag.push({cnt[i], i});
	}
	for(int i = 1; i <= n; ++i) {
		for(int x : pos[i]) ag.push({cnt[x], x});
		if((int)ag.size() == 0) return 0;
		pi x = ag.top();
		//if(xx == 1) cout << x.ND << " ";
		ag.pop();
		if(cnt[x.ND] > 0) {
			cnt[x.ND]--;
			if(i + xx + 1 <= n) pos[i + xx + 1].PB(x.ND);
		}
	}
	return 1;
}
		

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		int l = 0, r = n - 2, mid;
		while(l <= r) {
			mid = (l + r) / 2;
			if(check(mid)) l = mid + 1;
			else r = mid - 1;
			for(int i = 1; i <= n; ++i) cnt[i] = 0;
			for(int i = 1; i <= n; ++i) {
				cnt[a[i]]++;
			}
		}
		for(int i = 1; i <= n; ++i) cnt[i] = 0;
		cout << l - 1 << "\n";
	}
		
		
	
}