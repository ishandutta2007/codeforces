
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
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
const ll inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);





vector<bool> checked(4200000, false);
vector<bool> exist(4200000, false);
int n, m;
stack<int> st;

void dfs1(int x, int i) {
	if (checked[x]) {
		return;
	}
	checked[x] = true;
	if (exist[x]) {
		exist[x] = false;
		st.push(x);
	}
	for (int j = i; j < n; j++) {
		int mask = 1 << j;
		if ((x & mask)) {
			dfs1(x & ~mask, j + 1);
		}
	}
}



int main() {
	cin >> n >> m;
	vi a(m);
	rep(i, m) {
		cin >> a[i];
		exist[a[i]] = true;
	}
	int res = 0;
	int mask = (1 << n) - 1;
	rep(i, 1 << n) {
		if (!exist[i]) {
			continue;
		}
		res++;
		exist[i] = false;
		st.push(i);
		while (!st.empty()) {
			int u = st.top();
			st.pop();
			dfs1((~u) & mask, 0);
		}
	}
	cout << res << endl;
}