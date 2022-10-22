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

int arr[100020];
map<int, int> cvt, tvc; set<int> cs; int cc = 0;
bool dp[100020];
int ans[100020];

void Answer(int n){
	vector<int> v(n);
	for (int i = 0; i < n; i++){ v[i] = i+1; }
	bool ans = 0;
	do{
		bool flg = 1;
		for (int i = 0; i < n; i++){ flg &= (v[i] != i+1); }
		if (!flg){ continue; }
		for (int i = 0; i < n; i++){
			flg &= (arr[i+1] <= v[i]);
		}
		if (flg){
			for (int x : v){ cout << x << ' '; } ans = 1; break;
		}
	} while (next_permutation(all(v)));
	if (!ans){ cout << -1 << endl; }
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		for (int i = 1; i <= n; i++){
			if (arr[i-1] != arr[i]){
				cvt[ arr[i] ] = i;
			}
			tvc[i] = arr[i];
		}
		for (int i = 1; i <= n; i++){
			arr[i] = cvt[ arr[i] ];
		}
		for (int i = 1; i <= n; i++){ dp[i] = 0; } dp[0] = 1;
		for (int i = 1; i <= n; i++){
			if (i >= 2){
				dp[i] |= (i >= arr[i-1] && i-1 >= arr[i]) && dp[i-2];
			}
			if (i >= 3){
				dp[i] |= (i >= arr[i-2] && i-2 >= arr[i-1] && i-1 >= arr[i]) && dp[i-3];
			}
		}
		if (dp[n] == 0){ cout << -1; }
		else{
			int ptr = n;
			while (ptr > 0){
				if (dp[ptr-2]){ ans[ptr-1] = ptr; ans[ptr] = ptr-1; ptr -= 2; }
				else{ ans[ptr-2] = ptr; ans[ptr-1] = ptr-2; ans[ptr] = ptr-1; assert(dp[ptr-3]); ptr -= 3; }
			}
			for (int i = 1; i <= n; i++){ cout << ans[i] << ' '; }
		}
		cout << endl;
		cvt.clear(); tvc.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}