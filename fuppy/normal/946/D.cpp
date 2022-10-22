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
#define all(c) c.begin(),c.end()
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> s(n);
	vii one(n);
	rep(i, n) {
		cin >> s[i];
		rep(j, m) {
			if (s[i][j] == '1') {
				one[i].push_back(j);
			}
		}
	}

	/*
	rep(i, n) {
		rep(j, one[i].size()) {
			cout << one[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//*/

	vii mi(n, vi(k + 1));
	rep(i, n) {
		for (int a = 0; a <= min((int)one[i].size(), k); a++) {
			int nokori = one[i].size() - a;
			if (nokori == 0) {
				mi[i][a] = 0;
				continue;
			}
			int mm = inf;
			for (int j = 0; j + nokori - 1 < one[i].size(); j++) {
				mm = min(mm, one[i][j + nokori - 1] - one[i][j] + 1);
			}
			mi[i][a] = mm;
		}
	}

	/*
	rep(i, n) {
		rep(j, k + 1) {
			cout << mi[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//*/

	vii dp(n + 1, vi(k + 1, inf));
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, k + 1) {
			rep(l, k + 1) {
				if (j + l > k) {
					break;
				}
				dp[i + 1][j + l] = min(dp[i + 1][j + l], dp[i][j] + mi[i][l]);
			}
		}
	}
	
	/*
	rep(i, n + 1) {
		rep(j, k + 1) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	//*/
	cout << dp[n][k] << endl;


}