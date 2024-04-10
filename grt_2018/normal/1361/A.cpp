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

const int nax = 5 * 1000 * 100 + 10;
int n,m;
pi ord[nax];
vi V[nax];
int t[nax];
bool done[nax];
bool was[nax];

bool check() {
	for(int i = 1; i <= n; ++i) {
		for(auto x : V[i]) {
			if(t[x] == t[i]) return 0;
		}
	}
	return 1;
}

int main() {_
	cin >> n >> m;
	for(int a,b,i=0; i<m; ++i) {
		cin >>a >> b;
		V[a].PB(b);
		V[b].PB(a);
	}
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
		ord[i] = {t[i],i};
	}
	sort(ord+1, ord+n+1);
	if(!check()) {
		cout << "-1";
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		int v = ord[i].ND;
		for(int x : V[v]) {
			if(done[x]) was[t[x]] = 1;
		}
		bool ok = 1;
		for(int j = 1; j < (int)ord[i].ST; ++j) {
			if(!was[j]) {
				ok = 0;
				break;
			}
		}
		if(!ok) {
			cout << "-1";
			return 0;
		}
		done[v] = 1;
		for(int x : V[v]) {
			if(done[x]) was[t[x]] = 0;
		}
	}
	for(int i = 1; i <= n; ++i) {
		cout << ord[i].ND << " ";
	}
}