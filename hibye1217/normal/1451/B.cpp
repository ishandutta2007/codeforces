#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define endl '\n'
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		string s;
		cin >> n >> m >> s;
		while (m--){
			int st, ed;
			cin >> st >> ed; st--; ed--;
			bool chk = false;
			for (int i = st-1; i >= 0; i--){
				if (s[i] == s[st]) chk = true;
			}
			for (int i = ed+1; i < n; i++){
				if (s[i] == s[ed]) chk = true;
			}
			cout << (chk ? "YES" : "NO") << endl;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}