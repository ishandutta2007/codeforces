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
	ll p, x, y;
	cin>>p>>x>>y;
	ll c = x;
	bool det = false;
	while(c >= y && !det) {
		ll k = (c / 50) % 475;
		REP(i, 25) {
			k = (k * 96 + 42) % 475;
			if(26 + k == p) {
				det = true;
				break;
			}
		}
		c -= 50;
	}
	if(det) {
		cout<<0<<endl;
		return 0;
	}
	ll d = x;
	ll cnt = 0;
	while(!det) {
		ll k = (d / 50) % 475;
		REP(i, 25) {
			k = (k * 96 + 42) % 475;
			if(26 + k == p) {
				det = true;
				break;
			}
		}
		if(!det) {
			d += 50;
			++cnt;
		}
	}
	cout<<(cnt + 1) / 2<<endl;
 }