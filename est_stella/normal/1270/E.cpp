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

int n;
vector<int> ans;
int x[1010], y[10010];

int main() {
	fast;

	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> x[i] >> y[i];
	}

	while(ans.size() == 0 || ans.size() == n) {
		ans.clear();

		for(int i=1; i<=n; i++) {
			x[i] = x[i] + y[i];
			y[i] = x[i] - 2 * y[i];
			if(x[i] % 2 == 0) {
				ans.pb(i);
			}
			else {
				x[i]++;
				y[i]++;
			}

			x[i] /= 2;
			y[i] /= 2;
		}
	}

	cout << ans.size() << "\n";

	for(auto i : ans) cout << i << " ";
}