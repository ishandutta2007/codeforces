#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

typedef pair<pi2, int> pi3;
ll arr[200020];
queue<pi3> q;

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		if (arr[n-1] > arr[n]){ cout << -1 << endl; continue; }
		bool chk = 1;
		for (int i = 1; i < n; i++){
			if (arr[i] > arr[i+1]){ chk = 0; }
		}
		if (chk){ cout << 0 << endl; continue; }
		if (arr[n] < 0){ cout << -1 << endl; continue; }
		bool flg = 1;
		for (int i = n-2; i >= 1; i--){
			arr[i] = arr[n-1] - arr[n];
			q.push({ {i, n-1}, n });
		}
		if (!flg){ cout << -1 << endl; continue; }
		cout << q.size() << endl;
		while (!q.empty()){
			pi3 p = q.front(); q.pop();
			cout << p.fr.fr << ' ' << p.fr.sc << ' ' << p.sc << endl;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}