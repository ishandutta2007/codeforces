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

const int nax = 200*1000+10;
int n,k;
int t[nax];
int restrict[nax];

bool check(int x) {
	int wsk = 1;
	for(int i = 1; i <= k; ++i) {
		while(wsk <= n && t[wsk] < i) {
			wsk++;
		}
		if((n-wsk+1) > (ll)x * restrict[i]) return 0;
	}
	return 1;
}

int main() {_
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> t[i];
	for(int i = 1; i <= k; ++i) cin >> restrict[i];
	sort(t+1,t+n+1);
	int l = 1, r = n, mid;
	while(l<=r) {
		mid = (l+r)/2;
		if(check(mid)) r = mid-1;
		else l=mid+1;
	}
	cout << r+1 << "\n";
	for(int i = 0; i < r+1; ++i) {
		int cnt = 0;
		for(int j = i+1; j <= n; j+=r+1) {
			cnt++;
		}
		cout << cnt << " ";
		for(int j = i+1; j <= n; j+=r+1) {
			cout << t[j] << " ";
		}
		cout << "\n";
	}
	
}