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

const int N = 1500000;
vll soinsu(N);
vector<bool> isprime(N, true);

void prime(void) {
	ll i, j;
	isprime[0] = isprime[1] = false;
	for (i = 2; i < isprime.size(); i++) {
		if (isprime[i]) {
			soinsu[i].push_back(i);
			for (j = 2; i*j < isprime.size(); j++) {
				isprime[i*j] = false;
				soinsu[i * j].push_back(i);
			}
		}
	}
}



int main() {
	int n;
	cin >> n;
	prime();
	vl a(n);
	rep(i, n) {
		cin >> a[i];
	}
	set<ll> st;
	for (int i = 2; i < N; i++) {
		st.insert(i);
	}
	vl b(n);
	bool giri = true;
	rep(i, n) {
		if (!giri) {
			b[i] = *st.begin();
		}
		else {
			if (st.count(a[i])) {
				b[i] = a[i];
			}
			else {
				b[i] = *lower_bound(st.begin(), st.end(), a[i]);
				giri = false;
			}
		}

		rep(j, soinsu[b[i]].size()) {
			for (int k = 1; soinsu[b[i]][j] * k < N; k++) {
				st.erase(soinsu[b[i]][j] * k);
			}
		}

	}
	
	rep(i, n) {
		cout << b[i] << " ";
	}
	cout << endl;
}