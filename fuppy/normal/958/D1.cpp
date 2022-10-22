
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
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	vector<double> a(n);
	map<double, int> mp;
	rep(i, n) {
		int x, y, z;
		s[i].erase(s[i].begin());
		rep(j, s[i].size()) {
			if (s[i][j] == '+') {
				x = stoi(s[i].substr(0, j));
				s[i] = s[i].substr(j + 1, s[i].size() - j - 1);
				break;
			}
		}
		rep(j, s[i].size()) {
			if (s[i][j] == ')') {
				y = stoi(s[i].substr(0, j));
				s[i] = s[i].substr(j + 1, s[i].size() - j - 1);
				break;
			}
		}
		s[i].erase(s[i].begin());
		z = stoi(s[i]);
		a[i] = (double)(x + y) / z;
		mp[a[i]]++;
	}
	rep(i, n) {
		cout << mp[a[i]] << " ";
	}
	cout << endl;
}