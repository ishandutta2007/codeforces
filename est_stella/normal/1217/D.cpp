#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define pb push_back
#define pre(a) cout<<fixed; cout.precision(a);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n, m;
vector<int> g[5010];
queue<int> Q;
int in[5010];
int u[5010];
int v[5010];

int main() {
	fast;

	cin >> n >> m;

	for(int i=0; i<m; i++) {
		cin >> u[i] >> v[i];
		g[u[i]].eb(v[i]);
		in[v[i]]++;
	}

	for(int i=1; i<=n; i++) {
		if(in[i] == 0) Q.push(i);
	}

	int cnt = n;
	while(Q.size()) {
		cnt--;
		int x = Q.front();
		Q.pop();

		for(auto i : g[x]) {
			in[i]--;
			if(in[i] == 0) Q.push(i);
		}
	}

	if(cnt == 0) {
		cout << "1\n";
		for(int i=0; i<m; i++)
			cout << "1 ";
		return 0;
	}

	cout << "2\n";

	for(int i=0; i<m; i++) {
		if(u[i] < v[i]) cout << "1 ";
		else cout << "2 ";
	}
}