#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int SIZE = 1e6+5;

vi g[SIZE];
bool vis[SIZE];
int binaryLift[SIZE][21];

void dfs(int pos, int prev) {
	//if(binaryLift[pos][0]) { cout << "ops " << pos << endl; return; }
	//cout << pos << ' ' << prev << endl;
	binaryLift[pos][0] = prev;
	for(int a : g[pos]) {
		if(a != prev) {
			dfs(a, pos);
		}
	}
}

void setAllFrom(int i) {
	while(!vis[i]) {
		vis[i] = true;
		i = (binaryLift[i][0]);
	}
}

int getDist(int i, int potMax = 20) {
	int ans = 0;
	for(int pot = potMax; pot >= 0; pot--) {
		if(!vis[binaryLift[i][pot]]) {
			ans += (1 << pot);
			i = (binaryLift[i][pot]);
		}
	}
	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	//cout << "feito " << endl;
	dfs(n, n);
	//cout << "feito " << endl;
	for(int pot = 1; pot <= 20; pot++) {
		for(int i = 1; i <= n; i++) {
			binaryLift[i][pot] = binaryLift[binaryLift[i][pot-1]][pot-1];
		}
	}
	//cout << "feito " << endl;
	vis[n] = true;
	k = n - k - 1;
	for(int i = n - 1; i >= 1; i--) {
		if(vis[i]) continue;
		int x = getDist(i) + 1;
		if(x <= k) {
			setAllFrom(i);
			k -= x;
		}
	}
	for(int i = 1; i<= n; i++) {
		if(!vis[i]) {
			cout << i << ' ';
		}
	}
	cout << '\n';
	return 0;
}