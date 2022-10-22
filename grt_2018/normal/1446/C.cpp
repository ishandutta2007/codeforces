#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 200 * 1000 + 10;
int n;

int t[30 * nax][2], nr = 1;
int cnt[30 * nax];
int a[nax], res[nax];
map<int,int>sc;

void add(int x) {
	int v = 1;
	for(int i = 30; i >= 0; --i) {
		if(x & (1 << i)) {
			if(t[v][1] == 0) t[v][1] = ++nr;
			v = t[v][1];
		} else {
			if(t[v][0] == 0) t[v][0] = ++nr;
			v = t[v][0];
		}
		cnt[v]++;
	}
}

int f(int x) {
	int v = 1;
	int w = 0;
	for(int i = 30; i >= 0; --i) {
		bool b = (x & (1 << i));
		if(cnt[t[v][1 - b]] > 0) {
			w++;
		}
		v = t[v][b];
	}
	return w;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sc[a[i]] = i;
		add(a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int w = f(a[i]);
		ans = max(ans, w + 1);
	}
	cout << n - ans;
	
	
}