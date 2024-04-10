// kyopro.cpp : AvP[VGg |Cg`B
//

//#include "stdafx.h"


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
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p;//<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };


int main() {
	int n, m;
	cin >> n >> m;
	vector<pii> a(n);
	rep(i, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(all(a));
	vii G(n);
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		G[x].push_back(y); G[y].push_back(x);
	}
	vi ans(n);
	set<int> st;
	vi add;
	int skill = 0;
	rep(i, n) {
		if (skill < a[i].first) {
			rep(j, add.size()) {
				st.insert(add[j]);
			}
			add.clear();
		}
		skill = a[i].first;
		int res = st.size();
		int x = a[i].second;
		rep(j, G[x].size()) {
			if (st.count(G[x][j])) {
				res--;
			}
		}
		ans[x] = res;
		add.push_back(x);
	}
	rep(i, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
}