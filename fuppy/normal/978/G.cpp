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


struct days {
	int get, test, need, idx;
};

bool cmp(days a, days b) {
	return a.test < b.test;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<days> a(m);
	vi ans(n);
	rep(i, m) {
		cin >> a[i].get >> a[i].test >> a[i].need;
		a[i].get--; a[i].test--;
		a[i].idx = i;
		ans[a[i].test] = i + 1000;
	}
	sort(all(a), cmp);
	rep(i, m) {
		int j = a[i].get;
		int cnt = 0;
		while (cnt < a[i].need) {
			if (ans[j] - 1000 == a[i].idx) {
				cout << -1 << endl;
				return 0;
			}
			if (ans[j] == 0) {
				ans[j] = a[i].idx + 1;
				cnt++;
			}
			j++;
		}
	}

	rep(i, n) {
		cout << (ans[i] >= 1000 ? m + 1 : ans[i]) << " ";
	}
	cout << endl;
}