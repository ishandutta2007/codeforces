#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int n, q;
bool chk[3][100010];
int ans;

int cal(int x, int y) {
	if(!chk[x][y]) return 0;

	int ret = 0;
	for(int i=y-1; i<=y+1; i++) {
		if(i <= 0 || i > n) continue;

		if(chk[3-x][i]) ret++;
	}

	return ret;
}

int main() {
	fast;

	cin >> n >> q;

	for(int i=0; i<q; i++) {
		int r, c;
		cin >> r >> c;

		ans -= cal(r, c);

		chk[r][c] = !chk[r][c];

		ans += cal(r, c);

		if(ans > 0) cout << "No\n";
		else cout << "Yes\n";
	}
}