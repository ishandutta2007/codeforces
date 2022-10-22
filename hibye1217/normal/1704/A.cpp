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



void Main(){
	int t; cin >> t; while (t--){
		int l1, l2; string s1, s2; cin >> l1 >> l2 >> s1 >> s2;
		int idx = l1-l2; bool ans = 1;
		for (int i = 1; i < l2; i++){
			ans &= (s1[i+l1-l2] == s2[i]);
		}
		bool flg = 0;
		for (int i = 0; i <= idx; i++){
			flg |= (s1[i] == s2[0]);
		}
		cout << (ans&&flg ? "YES" : "NO") << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}