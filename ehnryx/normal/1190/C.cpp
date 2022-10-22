#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const string First = "tokitsukaze";
const string Second = "quailty";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	set<int> idx[2]; 

	function<bool(void)> check_win = [&] () {
		return idx[0].empty() || idx[1].empty();
	};
	function<bool(int)> check_lose = [&] (int i) {
		if (idx[0].empty() || idx[1].empty()) return false;
		if (!((max(*idx[0].rbegin(),i)-*idx[0].begin() < k && *idx[0].rbegin()-min(i-k+1,*idx[0].begin()) < k) || *idx[1].rbegin()-*idx[1].begin() < k)) return false;
		if (!((max(*idx[1].rbegin(),i)-*idx[1].begin() < k && *idx[1].rbegin()-min(i-k+1,*idx[1].begin()) < k) || *idx[0].rbegin()-*idx[0].begin() < k)) return false;
		return true;
	};

	FOR(i,k,n-1) {
		idx[s[i]-'0'].insert(i);
	}

	bool win = false;
	bool lose = true;
	win |= check_win();
	lose &= check_lose(k-1);

	FOR(i,k,n-1) {
		idx[s[i]-'0'].erase(i);
		idx[s[i-k]-'0'].insert(i-k);
		win |= check_win();
		lose &= check_lose(i);
	}

	assert(!(win && lose));

	if (win) cout << First << nl;
	else if (lose) cout << Second << nl;
	else cout << "once again" << nl;

	return 0;
}