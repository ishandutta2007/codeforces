#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

void Main(){
	int n; cin >> n;
	int st = 0, ed = n, ans = 0;
	int dlt = 0, lst = 0;
	int tot = 0;
	while (st <= ed){
		//cout << "P " << st << ' ' << ed << endl;
		int mid = st+ed >> 1;
		int req = (mid-dlt + n) % n;
		int res = 0;
		if (req == 0){ res = lst; }
		else{
			cout << "+ " << req << endl << flush;
			cin >> res;
		}
		tot += req;
		int val = (mid-dlt)/n;
		if (res-lst == val){ st = mid+1; }
		else{ ed = mid-1; ans = mid; }
		lst = res; dlt = mid;
	}
	cout << "! " << n-ans + tot << endl << flush;
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}