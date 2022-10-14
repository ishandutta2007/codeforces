#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int st[400005], mx[400005], mn[400005];
void upd(int root, int l, int r, int i, int val){
	if (i<l||i>r) return;
	if (l==r){
		st[root]=val; return;
	}
	int mid=(l+r)/2;
	upd(root*2+1, l, mid, i, val);
	upd(root*2+2, mid+1, r, i, val);
	st[root]=max(st[root*2+1], st[root*2+2]);
}

void upd2(int root, int l, int r, int i, int val){
	if (i<l||i>r) return;
	if (l==r){
		mx[root]=val; mn[root]=val; return;
	}
	int mid=(l+r)/2;
	upd2(root*2+1, l, mid, i, val);
	upd2(root*2+2, mid+1, r, i, val);
	mx[root]=max(mx[root*2+1], mx[root*2+2]);
	mn[root]=min(mn[root*2+1], mn[root*2+2]);
}

int query(int tr[], int root, int l, int r, int x, int y, bool inv=0){
	if (y<l||x>r) return inv?INT_MAX:INT_MIN;
	if (x<=l&&y>=r) return tr[root];
	int mid=(l+r)/2;
	if(!inv) return max(query(tr, root*2+1, l, mid, x, y, inv), query(tr, root*2+2, mid+1, r, x, y, inv));
	else return min(query(tr, root*2+1, l, mid, x, y, inv), query(tr, root*2+2, mid+1, r, x, y, inv));
}

int a[100005], pf[100005], lf[100005], rg[100005];
int32_t main(){
	fastio;
	int n; cin>>n;
	rep1(i, n){
		cin>>a[i]; upd(0, 0, n, i, a[i]);
	}
	upd2(0, 0, n-1, 0, 0);
	rep1(i, n) pf[i]=pf[i-1]+a[i], upd2(0, 0, n, i, pf[i]);
	rep1(i, n){
		if(i==1) lf[i]=1;
		else{
			int l=1, r=i;
			while (l<r){
				int mid=(l+r-1)/2;
				if(query(st, 0, 0, n, mid, i)==a[i]) r=mid;
				else l=mid+1;
			}
			lf[i]=l;
		}
		if(i==n) rg[i]=n;
		else{
			int l=i, r=n;
			while (l<r){
				int mid=(l+r+1)/2;
				if (query(st, 0, 0, n, i, mid)==a[i]) l=mid;
				else r=mid-1;
			}
			rg[i]=l;
		}
	}
	int ans=0;
	rep1(i, n) ans=max(ans, query(mx, 0, 0, n, i, rg[i])-query(mn, 0, 0, n, lf[i]-1, i-1, 1)-a[i]);
	cout<<ans<<endl;
}