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

const int nax = 500 * 1000 + 10;
int n;
pi e[nax];
vector<pi> V[(1<<20) + 10];
bool visited[(1<<20) + 10];
bool done[nax];
int I[(1<<20) + 10];
vi path;

void dfs(int x) {
	visited[x] = 1;
	for(auto nbh : V[x]) {
		if(!visited[nbh.ST]) {
			dfs(nbh.ST);
		}
	}
}

void dfsEu(int x) {
	while(I[x] < (int)V[x].size()) {
		auto nbh = V[x][I[x]++];
		int id = nbh.ND;
		if(id < 0) id = -id;
		if(!done[id]) {
			done[id] = 1;
			dfsEu(nbh.ST);
			path.PB(nbh.ND);
		}
	}
}
		

int main() {_
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> e[i].ST >> e[i].ND;
	}
	if(n == 1) {
		int x = e[1].ST ^ e[1].ND;
		for(int b = 20; b > 0; --b) {
			if(x % (1<<b) == 0) {
				cout << b << "\n" << "1 2";
				return 0;
			}
		}
		cout << "0\n1 2";
		return 0;
	}
	for(int b = 20; b > 0; --b) {
		for(int i = 0; i < (1<<b) + 5; ++i) {
			V[i].clear();
			visited[i] = 0;
		}
		for(int i = 1; i <= n; ++i) {
			int a = e[i].ST % (1 << b);
			int c = e[i].ND % (1 << b);
			V[a].PB({c, i});
			V[c].PB({a, -i});
		}
		int start = 0;
		for(int i = 0; i < (1<<b) + 5; ++i) {
			if((int)V[i].size() > 0) {
				start = i;
				break;
			}
		}
		dfs(start);
		bool ok = 1;
		for(int i = 0; i < (1<<b) + 5; ++i) {
			if((int)V[i].size() > 0) {
				if(!visited[i]) ok = 0;
				if((int)V[i].size() % 2 == 1) ok = 0;
			}
		}
		if(ok) {
			dfsEu(start);
			if((int)path.size() != n) {
				continue;
			}
			cout << b << "\n";
			for(int x : path) {
				if(x < 0) cout << (-x) * 2 - 1 << " " << (-x)  * 2 << " ";
				else cout << x * 2 << " " <<x*2 - 1<< " ";
			}
			return 0;
		}
	}
	cout << "0\n";
	for(int i = 1; i <= 2 * n; ++i) cout << i << " ";
	
}