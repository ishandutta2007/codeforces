#include <bits/stdc++.h>
#define MOD 32768
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,0,n)
		cin >> a[i];
	vector<int> dis(MOD, MOD);
	queue<int> q;
	dis[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		//cerr << cur << " " << dis[cur] << endl;
		q.pop();
		vector<int> adj;
		adj.push_back((cur+MOD-1)%MOD);
		if (cur%2 == 0) {
			adj.push_back((cur/2)%MOD);
			adj.push_back(((cur+MOD)/2)%MOD);
		}
		for (int to : adj) {
			if (dis[to] > dis[cur]+1) {
				dis[to] = dis[cur]+1;
				q.push(to);
			}
		}
	}
	rep(i,0,n)
		cout << dis[a[i]] << " ";
	cout << endl;
}