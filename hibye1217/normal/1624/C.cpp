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

bool chk[60];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		priority_queue<int> pq;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			pq.push(x);
		}
		bool flg = 1;
		while (!pq.empty()){
			int x = pq.top(); pq.pop();
			if (x == 0){ flg = 0; break; }
			if (x <= n){
				if (chk[x]){ pq.push(x/2); }
				else{ chk[x] = 1; }
			}
			else{ pq.push(x/2); }
		}
		if (flg){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }
		memset(chk, 0, sizeof(chk));
	}
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