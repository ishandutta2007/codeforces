#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int qx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int qy[8] = {0, 1, 1, 1, 0, -1, -1, -1};



int main(void) {
	ll n, k;
	cin>>n>>k;
	vector<ll> a(n);
	vector<ll> wa(n + 1);
	REP(i, n) cin>>a[i];
	REP(i, n + 1) {
		if(i == 0) wa[i] = 0;
		else {
			wa[i] = wa[i - 1] + a[i - 1];
		}
	}
	ll sum = 0;
	REP(i, n - k + 1) {
		sum += wa[i + k] - wa[i];
	}
	cout<<fixed<<showpoint<<setprecision(39)<<(double)sum/(double)(n - k + 1)<<endl;
}