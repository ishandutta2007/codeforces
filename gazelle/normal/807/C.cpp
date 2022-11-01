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
	int t;
	cin>>t;
	REP(i, t) {
		ll x, y, p, q;
		cin>>x>>y>>p>>q;
		ll k;
		if(y % q == 0) k = y / q;
		else k = y / q + 1;
		if(p == 0 && x != 0) {
			cout<<-1<<endl;
			continue;
		} else if(p == 0 && x == 0) {
			k = max(k, (ll)0);
		} else if(x % p == 0) k = max(k, x / p);
		else k = max(k, x / p + 1);
		if(q - p == 0 && y - x != 0) {
			cout<<-1<<endl;
			continue;
		} else if(q - p == 0 && y - x == 0) {
			k = max(k, (ll)0);
		} else if((y - x) % (q - p) == 0) k = max(k, (y - x) / (q - p));
		else k = max(k, (y - x) / (q - p) + 1);
		cout<<k * q - y<<endl;
	}
}