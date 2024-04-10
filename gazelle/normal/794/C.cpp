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
	string  s, t;
	cin>>s>>t;
	sort(ALL(s));
	sort(ALL(t), greater<char>());
	ll n = s.size();
	string ans = "";
	ans.resize(n);
	s = s.substr(0, (n + 1) / 2);
	t = t.substr(0, n / 2);
	ll iro1t = 0;
	ll iro1f = s.size() - 1;
	ll iro2t = 0;
	ll iro2f = t.size() - 1;
	ll tail = n - 1;
	REP(i, n) {
		if(i % 2 == 0) {
			if(t[iro2t] <= s[iro1t]) {
				ans[tail] = s[iro1f];
				--tail;
				--iro1f;
			} else {
				ans[i] = s[iro1t];
				iro1t++;
			}
		} else {
			if(t[iro2t] <= s[iro1t]) {
				ans[tail] = t[iro2f];
				--tail;
				--iro2f;
			} else {
				ans[i] = t[iro2t];
				iro2t++;
			}
		}
	}
	cout<<ans<<endl;
}