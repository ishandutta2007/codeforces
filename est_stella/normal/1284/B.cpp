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

ll n;
ll ans;
vector<int> Max, Min;

int main() {
	fast;

	cin >> n;

	for(int i=0; i<n; i++) {
		int l;
		cin >> l;

		int flag = 0;
		int mx = -1, mn = 1e7, x;
		for(int j=0; j<l; j++) {
			cin >> x;

			if(x > mn) {
				flag = 1;
			}

			mx = max(mx, x);
			mn = min(mn, x);
		}

		if(flag == 0) {
			Max.pb(mx);
			Min.pb(mn);
		}
	}	

	sort(all(Max));
	sort(all(Min));

	ans = n * n;
	for(auto i : Min) {
		ans -= upper_bound(all(Max), i) - Max.begin();
	}

	cout << ans;
}