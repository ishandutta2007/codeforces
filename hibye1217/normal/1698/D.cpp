#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define mkp make_pair
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
template <typename T> using priority_stack = priority_queue< T, vector<T>, greater<T> >;

vector<int> ask(int st, int ed){ int len = ed-st+1;
	cout << "? " << st << ' ' << ed << endl << flush;
	vector<int> res;
	for (int i = 1; i <= len; i++){
		int x; cin >> x;
		if (x == -1){ exit(0); }
		res.push_back(x);
	}
	return res;
}
int ans(int x){ cout << "! " << x << endl << flush; }

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int st = 1, ed = n;
		while (st+1 < ed-1){
			int mid = st+ed >> 1;
			vector<int> v = ask(st, mid);
			int cnt = 0, len = mid-st+1;
			for (int x : v){ cnt += (st > x || x > mid); }
			if ((cnt-len) & 1){ ed = mid; } else{ st = mid; }
		}
		int x1 = ask(st, st)[0], x3 = ask(ed, ed)[0];
		if (x1 == st){ ans(x1); } else if (x3 == ed){ ans(x3); }
		else{ ans(st+ed >> 1); }
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}