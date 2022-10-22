#include<bits/stdc++.h>
using namespace std;
#define ll   long long
#define ld   long double
#define ull  unsigned long long
#define fi   first
#define se   second
#define pb   push_back
#define pob  pop_back
#define mp   make_pair
#define pque priority_queue
#define endl '\n'
typedef vector <int> 	vi;
typedef vector <ll>		vll;
typedef pair <int, int> ii;
typedef pair <int, int> llll;
typedef vector <vi > 	vvi;
typedef vector <vll > 	vvll;
typedef vector <ii > 	vii;
typedef vector <llll > 	vllll;

const ll N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, x, y;
	cin >> n >> m;
	bool ck[m];
	memset(ck, 0, sizeof(ck));
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		x--;
		y--;
		for (int j = x; j <= y; j++){
			ck[j] = 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++){
		if (!ck[i]){
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < m; i++){
		if (!ck[i]){
			cout << i + 1 << ' ';
		}
	}
}