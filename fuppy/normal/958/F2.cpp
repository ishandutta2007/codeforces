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




int main() {
	int n, m;
	cin >> n >> m;
	vi cnt(m);
	vi a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vi moku(m);
	rep(i, m) {
		cin >> moku[i];
	}
	int left = 0, right = 0;
	int ans = inf;
	bool lack = true, many = false;
	set<int> no;
	rep(i, m) {
		if (moku[i]) {
			no.insert(i);
		}
	}
	int yojou = 0;
	while (left < n) {
		if (!no.empty()) {
			if (right == n) {
				break;
			}
			cnt[a[right]]++;
			if (cnt[a[right]] == moku[a[right]]) {
				no.erase(a[right]);
			}
			else if (cnt[a[right]] > moku[a[right]]) {
				yojou++;
			}
			right++;
		}
		else {
			cnt[a[left]]--;
			if (cnt[a[left]] >= moku[a[left]]) {
				yojou--;
			}
			else if (cnt[a[left]] == moku[a[left]] - 1) {
				no.insert(a[left]);
			}
			left++;
		}
		if (no.size() == 0) {
			ans = min(ans, yojou);
		}
	}
	if (no.size() == 0) {
		ans = min(ans, yojou);
	}
	cout << ((ans == inf) ? -1 : ans) << endl;
}