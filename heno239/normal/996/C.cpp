#include<iostream>
#include<cstdio>
#include<string>
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
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
struct mov { int num, x, y; };
int main() {
	int n, k; cin >> n >> k;
	int road[4][50];
	rep(i, 4) {
		rep(j, n) {
			cin >> road[i][j];
		}
	}
	bool f = false;
	if (k < 2 * n)f = true;
	else {
		rep(i, n) {
			if (road[0][i] == road[1][i] || road[2][i] == road[3][i])f = true;
		}
	}
	if (!f) {
		cout << -1 << endl;
	}
	else {
		queue<mov> q;
		int cnt = 0;
		while(true) {
			bool g = false;
			rep(i, n-1) {
				if (road[1][i] == 0)continue;
				if (road[1][i] == road[0][i]) {
					q.push({ road[1][i],1,i + 1 }); cnt++; g = true;
					road[1][i] = 0;
				}
				else if(road[1][i+1]==0){
					road[1][i + 1] = road[1][i];
					q.push({ road[1][i],2,i + 2 }); cnt++; g = true;
					road[1][i] = 0;
				}
			}
			if (road[1][n-1]>0&&road[1][n-1] == road[0][n-1]) {
				q.push({ road[1][n - 1],1,n }); cnt++; g = true;
				road[1][n - 1] = 0;
			}
			else if(road[1][n-1]>0&&road[2][n-1]==0){
				road[2][n - 1] = road[1][n-1];
				q.push({ road[1][n - 1],3,n }); cnt++; g = true;
				road[1][n - 1] = 0;
			}
			Rep(i, 1, n) {
				if (road[2][i] == 0)continue;
				if (road[2][i] == road[3][i]) {
					q.push({ road[2][i],4,i + 1 }); cnt++; g = true;
					road[2][i] = 0;
				}
				else if(road[2][i-1]==0){
					road[2][i - 1] = road[2][i];
					q.push({ road[2][i],3,i }); cnt++; g = true;
					road[2][i] = 0;
				}
			}
			if (road[2][0]>0&&road[2][0] == road[3][0]) {
				q.push({ road[2][0],4,1 }); cnt++; g = true;
				road[2][0] = 0;
			}
			else if(road[2][0]>0&&road[1][0]==0){
				road[1][0] = road[2][0];
				q.push({ road[2][0],2,1 }); cnt++; g = true;
				road[2][0] = 0;
			}
			if (!g)break;
		}
		cout << cnt << endl;
		while (!q.empty()) {
			mov out = q.front(); q.pop();
			cout << out.num << " " << out.x << " " << out.y << endl;
		}
	}
	return 0;
}