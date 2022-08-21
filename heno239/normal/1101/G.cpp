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
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

typedef vector<int> vec;
typedef vector<vec> mat;
//bit.ver
//rank
int Gaussian_elimination(mat &A) {
	int n = A.size(); int m = A[0].size();
	int le = 0;
	rep(j, m) {
		Rep(i, le, n) {
			if (A[i][j]) {
				swap(A[le], A[i]);
				Rep(i2, le + 1, n) {
					if (A[i2][j]) {
						rep(k, m) {
							A[i2][k] ^= A[le][k];
						}
					}
				}
				le++; break;
			}
		}
	}
	return le;
}
int n;
mat A;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	A.resize(n);
	int sum = 0;
	rep(i, n) {
		int x; cin >> x; sum ^= x;
		vec v;
		rep(j, 31) {
			if (sum&(1 << j)) {
				v.push_back(1);
			}
			else {
				v.push_back(0);
			}
		}
		A[i] = v;
	}
	if (sum == 0)cout << -1 << endl;
	else {
		cout << Gaussian_elimination(A) << endl;
	}
	//stop
	return 0;
}