//#include "stdafx.h";


#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000009;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p <<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };


int n;
vi p;
vi used;
vii G;
int root;
vl ans;

bool dfs(int now, int parent) {
	int cnt = 0;
	if (parent != -1) {
		cnt = 1;
	}
	rep(i,G[now].size()) {
		int child = G[now][i];
		if (parent == child) {
			continue;
		}
		else {
			if (!dfs(child, now)) {
				cnt++;
			}
		}
	}
	if (cnt % 2 == 0) {
		ans.push_back(now);
		used[now] = true;
		return true;
	}
	else {
		return false;
	}
}

bool dfs2(int now, int parent) {
	if (!used[now]) {
		ans.push_back(now);
		used[now] = true;
	}
	rep(i, G[now].size()) {
		int child = G[now][i];
		if (parent == child) {
			continue;
		}
		dfs2(child, now);
	}
	return true;
}

int main() {
	cin >> n;
	p.resize(n);
	used.resize(n, false);
	G.resize(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
		if (p[i] >= 0) {
			G[i].push_back(p[i]);
			G[p[i]].push_back(i);
		}
		else {
			root = i;
		}
	}
	if (dfs(root, -1)) {
		cout << "YES" << endl;
		dfs2(root, -1);
		rep(i, n) {
			cout << ans[i] + 1 << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}
}