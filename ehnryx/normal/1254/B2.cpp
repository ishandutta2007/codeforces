#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6+1;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;

	int a[n];
	ll sum = 0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		sum += a[i];
	}
	if(sum==1) {
		cout<<-1<<nl;
		return 0;
	}

	vector<ll> div;
	for(ll i=2;i*i<=sum;i++) {
		if(sum%i == 0) {
			div.push_back(i);
			if(i*i != sum) div.push_back(sum/i);
		}
	}
	div.push_back(sum);
	sort(div.begin(),div.end());

	int m = div.size();
	vector<bool> vis(m);

	ll ans = INFLL;
	for(int i=0;i<m;i++) {
		if(vis[i]) continue;
		for(int j=i;j<m;j++) {
			if(div[j] % div[i] == 0) {
				vis[j] = true;
			}
		}

		//cerr<<"try div "<<div[i]<<nl;

		ll left = 0;
		ll right = 0;
		ll cur = 0;
		for(int j=0;j<n;j++) {
			assert(left==0 || right==0);
			//cerr<<"@ "<<j<<" take "<<left<<" put "<<right<<nl;
			cur += left + right;
			ll take = min((ll)a[j],left);
			ll here = a[j] - take + right;
			left -= take;
			right = 0;
			//cerr<<"makes "<<here<<nl;
			if(here % div[i] == 0) continue;
			ll rem = here % div[i];
			//cerr<<"do rem "<<rem<<nl;
			if(rem < div[i]-rem) {
				right += rem;
				//cerr<<"right upd to "<<right<<nl;
			} else {
				left += div[i]-rem;
				//cerr<<"left upd to "<<left<<nl;
			}
		}
		assert(left==0 && right==0);
		//cerr<<"get "<<cur<<nl<<nl;
		ans = min(ans,cur);
	}

	cout<<ans<<nl;

	return 0;
}