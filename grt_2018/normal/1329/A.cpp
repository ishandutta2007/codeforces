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
int n,m;
int l[nax];
int p[nax];
ll sum;

int main() {_
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> l[i];
		sum += l[i];
	}
	if(sum<n) {
		cout<<"-1";
		return 0;
	}
	for(int i = 1; i <= m; ++i) {
		if(l[i] + i - 1 > n) {
			cout << "-1";
			return 0;
		}
		p[i] = i;
	}
	int w = n, pos = m;
	while(pos > 0) {
		if(p[pos] + l[pos] -1  < w) {
			p[pos] = w - l[pos]+1;
			w = p[pos] - 1;
			pos--;
		} else {
			break;
		}
	}
	if(p[1]!=1) {
		cout<<"-1";
		return 0;
	}
	for(int i=1; i<=m; i++) cout<<p[i]<<" ";	
	
	
}