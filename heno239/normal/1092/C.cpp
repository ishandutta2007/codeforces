#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
//#define revstr(s) reverse(s.begin(),s.end())
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
pair<string,int> a[100][2];
string ms,mp;
bool inp(string x) {
	int len = x.length();
	if (x == mp.substr(0, len))return true;
	else return false;
}
bool ins(string x) {
	int len = x.length();
	if (x == ms.substr(ms.length() - len,len))return true;
	else return false;
}
char out[200];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, 2*n-2) {
		string s; cin >> s;
		int l = s.length();
		if (a[l][0].first == "")a[l][0] = { s,i };
		else a[l][1] = { s,i };
	}
	bool valid = true;
	ms = a[n - 1][0].first, mp = a[n - 1][1].first;
	out[a[n - 1][0].second] = 'S';
	out[a[n - 1][1].second] = 'P';
	rep1(i, n - 2) {
		string z1 = a[i][0].first,z2=a[i][1].first;
		if (inp(z1) && ins(z2)) {
			out[a[i][0].second] = 'P';
			out[a[i][1].second] = 'S';
		}
		else if(inp(z2)&&ins(z1)){
			out[a[i][0].second] = 'S';
			out[a[i][1].second] = 'P';
		}
		else {
			valid = false;
		}
	}
	if (valid) {
		rep(i, 2 * n - 2)cout << out[i];
		cout << endl;
	}
	else {
		mp = a[n - 1][0].first, ms = a[n - 1][1].first;
		out[a[n - 1][0].second] = 'P';
		out[a[n - 1][1].second] = 'S';
		rep1(i, n - 2) {
			string z1 = a[i][0].first, z2 = a[i][1].first;
			if (inp(z1) && ins(z2)) {
				out[a[i][0].second] = 'P';
				out[a[i][1].second] = 'S';
			}
			else if (inp(z2) && ins(z1)) {
				out[a[i][0].second] = 'S';
				out[a[i][1].second] = 'P';
			}
			else {
				valid = false;
			}
		}
		rep(i, 2 * n - 2)cout << out[i];
		cout << endl;
	}
	return 0;
}