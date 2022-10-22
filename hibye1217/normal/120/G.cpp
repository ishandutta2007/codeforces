#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

typedef pair<pi2, pi2> pi4;
typedef pair<string, pi2> psi2;
pi2 arr[120][2];
queue<psi2> q;
int d[120][120];
vector<string> ans[120];

void Main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, t; cin >> n >> t;
	for (int i = 1; i <= n; i++){
		cin >> arr[i][0].fr >> arr[i][0].sc;
		cin >> arr[i][1].fr >> arr[i][1].sc;
	}
	int m; cin >> m;
	for (int i = 1; i <= m; i++){
		string s; int c;
		cin >> s >> c;
		q.push({s, {c, i}});
	}
	int ti = 0, pi = 0;
	bool cor = 0; int lt = 0;
	while (!q.empty()){
		if (!cor || lt == 0){
			ti += 1;
			if (ti > n){
				ti = 1;
				pi ^= 1;
			}
			lt = t;
		}
		string s = q.front().fr;
		int c = q.front().sc.fr, idx = q.front().sc.sc;
		q.pop();
		int tim = max(1, c - (arr[ti][pi].fr + arr[ti][pi^1].sc) - d[ti][idx]);
		if (tim > lt){
			//cout << "NO " << ti << ' ' << pi << ' ' << s << endl;
			d[ti][idx] += lt; cor = 0;
			q.push({s, {c, idx}});
		}
		else{
			//cout << "*** OK " << ti << ' ' << pi << ' ' << s << endl;
			ans[ti].push_back(s); lt -= tim; cor = 1;
		}
	}
	for (int i = 1; i <= n; i++){
		cout << ans[i].size();
		for (string s : ans[i]){ cout << ' ' << s; }
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