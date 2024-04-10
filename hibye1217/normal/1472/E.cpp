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

typedef pair<pii, int> piii;

piii arr[200020];
int ans[200020];

void Main(){
	int t;
	cin >> t;
	while (t--){
		memset(ans, -1, sizeof(ans));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			int x, y;
			cin >> x >> y;
			arr[i] = { {min(x,y), max(x,y)}, i };
		}
		sort(arr+1, arr+n+1);
		int p = 1;
		set<pii> s;
		for (int i = 1; i <= n; i++){
			int w = arr[i].fr.fr, h = arr[i].fr.sc;
			int idx = arr[i].sc;
			if (arr[p].fr.fr != w){
				for (p; p < i; p++){
					s.insert({ arr[p].fr.sc, arr[p].sc });
				}
			}
			pii sp = *(s.begin());
			if (s.size() == 0 || sp.fr >= h){
				ans[idx] = -1;
			}
			else{
				ans[idx] = sp.sc;
			}
		}
		for (int i = 1; i <= n; i++){
			cout << ans[i] << ' ';
		}
		cout << endl;
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