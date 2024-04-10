#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

struct Triple {
	int x,y,z;
};

const int nax = 10000 + 10;
int n,t;
long long a[nax];
int sum;
vector<Triple>ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		sum = 0;
		cin >> n;
		ans = {};
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		if(sum % n != 0) {
			cout << "-1\n";
			continue;
		}
		int tar = sum / n;
		for(int i = 2; i <= n; ++i) {
			int ile = (a[i] / i) * i;
			if(ile < a[i]) ile += i;
			ile = ile - a[i];
			ans.PB({1, i, ile});
			a[1] -= ile;
			a[i] += ile;
			ans.PB({i, 1, a[i]/i});
			a[i] = 0;
			a[1] += a[i];
		}
		for(int i = 2; i <= n; ++i) {
			ans.PB({1, i, tar});
		}
		//cout << "\n";
		
		cout << (int)ans.size() << "\n";
		for(auto it : ans) {
			cout << it.x << " " << it.y << " " << it.z << "\n";
		}
	}
	
}