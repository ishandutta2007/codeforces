
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
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p <<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };



#define P complex<ll>

#define EPS (1e-10)

// O (cross product) : a~b = |a||b|sin
ll cross(P a, P b) {
	return (a.real() * b.imag() - a.imag() * b.real());
}


// a1,a2[_b1,b2[_
int is_intersected_ls(P a1, P a2, P b1, P b2) {
	return (cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < EPS) &&
		(cross(b2 - b1, a1 - b1) * cross(b2 - b1, a2 - b1) < EPS);
}


int main() {
	int n, m;
	cin >> n >> m;
	if (n != m) {
		cout << "No" << endl;
		return 0;
	}
	vector<P> a(n), b(n);
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		a[i].real(x); a[i].imag(y);
	}
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		b[i].real(x); b[i].imag(y);
	}
	vi idx(n);
	rep(i, n) {
		idx[i] = i;
	}
	bool flag = false;
	do {
		bool flag2 = true;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (is_intersected_ls(a[i], b[idx[i]], a[j], b[idx[j]])) {
					flag2 = false;
					i = 1000;
					break;
				}
			}
		}
		if (flag2) {
			flag = true;
			break;
		}
	} while (next_permutation(idx.begin(), idx.end()));
	cout << (flag ? "Yes" : "No") << endl;

}