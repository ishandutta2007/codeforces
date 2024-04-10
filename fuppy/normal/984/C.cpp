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
#define fio() cin.tie(0); ios::sync_with_stdio(false);



ll gcd(ll a, ll b) {
	if (b > a) {
		swap(a, b);
	}
	ll r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	fio()
	ll n;
	cin >> n;
	while (n--) {
		ll p, q, b;
		cin >> p >> q >> b;
		if (p == 0) {
			cout << "Finite" << endl;
			continue;
		}
		ll g = gcd(p, q);
		p /= g; q /= g;
		if (q == 1) {
			cout << "Finite" << endl;
			continue;
		}
		bool flag = false;
		while (true) {
			g = gcd(q, b);
			if (g == 1) {
				break;
			}
			while (q% g == 0) {
				q /= g;
			}
			b = g;
			if (q == 1) {
				flag = true;
				break;
			}
		}
		cout << (flag ? "Finite" : "Infinite") << endl;
	}
}