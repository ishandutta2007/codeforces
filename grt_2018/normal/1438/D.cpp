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

struct Triple {
	int x,y,z;
};

const int nax = 100 * 1000 + 10;
int n;
int a[nax];
vector<Triple> ans = {};

int main() {_
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 2; i+1 <= n; i += 2) {
		ans.PB({1, i, i + 1});
		int x = a[1] ^ a[i] ^ a[i + 1];
		a[1] = a[i] = a[i + 1] = x;
	}
	for(int i = 2; i+1 <= n; i += 2) {
		ans.PB({1, i, i + 1});
		int x = a[1] ^ a[i] ^ a[i + 1];
		a[1] = a[i] = a[i + 1] = x;
	}
	bool ok = 1;
	//~ cout << a[1] << " ";
	for(int i = 2; i <= n; ++i) {
		//~ cout << a[i] << " ";
		if(a[i] != a[i - 1]) ok = 0;
	}
	if(!ok) cout << "NO\n";
	else {
		cout << "YES\n";
		cout << (int)ans.size() << "\n";
		for(auto x : ans) {
			cout << x.x << " " << x.y << " " <<x.z << "\n";
		}
	}
}