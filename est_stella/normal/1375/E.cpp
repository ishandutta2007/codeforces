#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int n;
int a[1010];
int lo[1010];
vector<pii> v;
vector<pii> ans;

int main() {
	fast;

	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> a[i];
		v.eb(a[i], i);
	}

	sort(all(v));

	for(int i=1; i<=n; i++) {
		a[i] = lower_bound(all(v), mp(a[i], i)) - v.begin() + 1;

		lo[a[i]] = i;
	}

	for(int i=1; i<=n; i++) {
		for(int j=i-1; j>=1; j--) {
			if(lo[j+1] < lo[j]) {
				swap(a[lo[j+1]], a[lo[j]]);
				swap(lo[j+1], lo[j]);

				ans.eb(lo[j], lo[j+1]);
			}
		}
	}

	cout << ans.size() << "\n";

	for(auto i : ans) {
		cout << i.fi << " " << i.se << "\n";
	}
}