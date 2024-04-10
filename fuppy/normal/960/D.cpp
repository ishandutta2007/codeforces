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
#define Sp(p) cout<<setprecision(15)<< fixed<<p;//<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
	int q;
	cin >> q;
	vl num(61);
	vl mod(61);
	mod[0] = 1;
	rep(i, 60) {
		mod[i + 1] = mod[i] * 2;
	}
	rep(aaa, q) {
		int t;
		cin >> t;
		if (t == 1) {
			ll x, k;
			cin >> x >> k;
			ll depth = 60;
			while ((x & (1LL << depth)) == 0) {
				depth--;
			}
			k %= mod[depth];
			num[depth] += k;
			num[depth] %= mod[depth];
			while (num[depth] < 0) {
				num[depth] += mod[depth];
			}
		}
		else if (t == 2) {
			ll x, k;
			cin >> x >> k;
			ll depth = 60;
			while ((x & (1LL << depth)) == 0) {
				depth--;
			}
			for (; depth <= 60; depth++) {
				k %= mod[depth];
				num[depth] += k;
				num[depth] %= mod[depth];
				while (num[depth] < 0) {
					num[depth] += mod[depth];
				}
				k *= 2;
			}
		}
		else {
			ll x;
			cin >> x; 
			ll depth = 60;
			while ((x & (1LL << depth)) == 0) {
				depth--;
			}
			while (depth >= 0) {
				cout << x << " ";
				x -= mod[depth];
				x += num[depth];
				x %= mod[depth];
				while (x < 0) {
					x += mod[depth];
				}
				x += mod[depth];
				x /= 2;
				depth--;
				if (depth >= 0) {
					x -= num[depth];
					x %= mod[depth];
					while (x < 0) {
						x += mod[depth];
					}
					x += mod[depth];
				}
			}
			cout << endl;
		}
	}
}