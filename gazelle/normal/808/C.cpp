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
	ll n, w;
	cin>>n>>w;
	vector<pair<double, int> > a(n);
	vector<ll> t(n, 0);
	REP(i, n) {
		cin>>a[i].first;
		a[i].second = i;
	}
	sort(ALL(a));
	bool det = true;
	REP(i, n) {
		if((int)(a[i].first + 0.0000001) % 2 == 0) {
			t[a[i].second] = (int)(a[i].first + 0.0000001) / 2;
			w -= (int)(a[i].first + 0.0000001) / 2;
		} else {
			t[a[i].second] = (int)(a[i].first + 0.0000001) / 2 + 1;
			w -= (int)(a[i].first + 0.0000001) / 2 + 1;
		}
		if(w < 0) det = false;
	}
	if(!det) {
		cout<<-1<<endl;
		return 0;
	}
	REP(i, n) {
		if((int)(a[n - 1 - i].first + 0.0000001) - t[a[n - 1 - i].second] <= w) {
			w -= (int)(a[n - 1 - i].first + 0.0000001) - t[a[n - 1 - i].second];
			t[a[n - 1 - i].second] = (int)(a[n - 1 - i].first + 0.0000001);
		} else {
			t[a[n - 1 - i].second] += w;
			w = 0;
			break;
		}
	}
	REP(i, n) {
		cout<<t[i];
		if(i != n - 1) cout<<" ";
		else cout<<endl;
	}
}