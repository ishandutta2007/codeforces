#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

vector<pii> ans;

inline void f(int x){
	//cout << "F " << x << endl;
	if (x <= 2) return;
	int k = sqrt(x) + 1;
	for (int i = k+1; i < x; i++){
		ans.push_back({i, x});
	}
	ans.push_back({x, k});
	ans.push_back({x, k});
	f(k);
}

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		f(n);
		cout << ans.size() << endl;
		for (pii p : ans){
			cout << p.fr << ' ' << p.sc << endl;
		}
		ans.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}