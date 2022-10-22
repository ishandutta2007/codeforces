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

int n;
int cnt[100*1000+10];
int sum, even;

int main() {_
	cin >> n;
	for(int a, i = 1; i <= n; ++i) {
		cin >> a;
		cnt[a]++;
		if(cnt[a] % 2 == 0) even++;
	}
	int fr = 0;
	for(int i = 1; i <= 100 * 1000; ++i) fr += (cnt[i] >= 4);
	sum = n;
	int q;
	cin >> q;
	while(q--) {
		char c; int x;
		cin >> c >> x;
		if(c == '+') {
			cnt[x]++;
			sum++;
			if(cnt[x] % 2 == 0) even++;
			if(cnt[x] == 4) fr++;
		} else {
			cnt[x]--;
			sum--;
			if(cnt[x] % 2 == 1) even--;
			if(cnt[x] == 3) fr--;
		}
		//cout << p << " " << sum << " " << even << " ";
		if(even < 4 || fr < 1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
		
	
}