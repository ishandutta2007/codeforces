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



#define P complex<ll>



// O (cross product) : a~b = |a||b|sin
ll cross(P a, P b) {
	return (a.real() * b.imag() - a.imag() * b.real());
}

// _ca,b
int is_point_on_line(P a, P b, P c) {
	return cross(b - a, c - a) == 0;
}


int main() {
	int n;
	cin >> n;
	if (n <= 3) {
		cout << "YES" << endl;
		return 0;
	}
	vector<P> xy(n);
	rep(i, n) {
		ll x, y;
		cin >> x >> y;
		xy[i].real(x);
		xy[i].imag(y);
	}
	vector<bool> used(n, false);
	for (int j = 0; j <= 2; j++) {
		for (int k = j + 1; k <= 2; k++) {
			fill(used.begin(), used.end(), false);
			used[k] = used[j] = true;
			int cnt = 2;
			for (int i = 0; i < n; i++) {
				if (used[i]) {
					continue;
				}
				if (is_point_on_line(xy[j], xy[k], xy[i])) {
					used[i] = true;
					cnt++;
				}
			}
			vector<P> two;
			rep(i, n) {
				if (used[i]) {
					continue;
				}
				if (two.size() < 2) {
					used[i] = true;
					two.push_back(xy[i]);
					cnt++;
				}
				else {
					if (is_point_on_line(two[0], two[1], xy[i])) {
						used[i] = true;
						cnt++;
					}
				}
			}
			if (cnt == n) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}