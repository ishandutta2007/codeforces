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

const int nax = 2000 + 10;
int n,p;
int a[nax];
int cnt[nax];

bool eval(int x) {
	for(int i = 0; i <= n; ++i) {
		cnt[i] = 0;
	}
	for(int i = 0; i < n; ++i) {
		cnt[max(0,a[i] - x)]++;
	}
	ll ilo = 1, sum = 0;
	for(int i = 0; i < n; ++i) {
		sum = (sum + cnt[i]);
		if(sum - i <= 0) {
			return 0;
		}
		ilo = ((ll)ilo * (sum - i + p))%p;
	}
	if(ilo == 0) {
		return 0;
	}
	return 1;
}
	
	
vi ans;

int main() {_
	cin >> n >> p;
	int mx= 0 ;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		mx = max(mx,a[i]);
	}
	for(int i = 1; i < mx; ++i) {
		if(eval(i)) {
			ans.PB(i);
		}
	}
	cout << (int)ans.size() << "\n";
	for(auto it : ans) {
		cout << it << " ";
	}
	
}