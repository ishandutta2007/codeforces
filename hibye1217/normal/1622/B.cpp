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

typedef pair<pi2, int> pi3;
int arr[200020];
pi3 srt[200020];
int ans[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		string s; cin >> s; s = " " + s;
		for (int i = 1; i <= n; i++){
			srt[i] = { { s[i], arr[i] }, i };
		}
		sort(srt+1, srt+n+1, [](pi3 a, pi3 b){
			return a > b;
		});
		for (int i = 1; i <= n; i++){
			ans[ srt[i].sc ] = n+1 - i;
		}
		for (int i = 1; i <= n; i++){ cout << ans[i] << ' '; }
		cout << endl;
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