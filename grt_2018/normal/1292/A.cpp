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

const int nax = 100*1000+10;
int n,q;
bool valid[2][nax];
ll cnt;

int main() {_
	cin >> n >> q;
	while(q--) {
		int a,b;
		cin >> a >> b;
		a--;
		int sum = valid[1-a][b] + valid[1-a][b-1] + valid[1-a][b+1];
		if(!valid[a][b]) {
			cnt += sum;
		} else {
			cnt -= sum;
		}
		valid[a][b] = 1 -  valid[a][b];
		if(cnt > 0) cout << "NO\n";
		else cout << "YES\n";
	}
	
}