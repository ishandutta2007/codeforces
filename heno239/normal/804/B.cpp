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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s; cin >> s; int n = s.length();
	ll t = 1;
	ll out = 0;
	per(i, n-1) {
		if (s[i] == 'a'&&s[i+1]=='b') {
			out = (out + t)%mod; t = t * 2 % mod;
			swap(s[i], s[i + 1]);
		}
		else if(s[i]=='b'&&s[i+1]=='b'){
			t = (t + 1) % mod;
		}
	}
	cout << out << endl;
	return 0;
}