#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define L (nd<<1)
#define R L|1
#define mid (s + e)>>1
#define ln '\n'
#define MAX (ll)(1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int n, x, t;
void solve(){
	cin >> n;
	map <int, int> ct2; 
	vi v;
	int tn = n;
	while(n--){
		cin >> x;
		v.pb(x);
	}
	set <int> s1, s2;
	vector <pii> ans; 
	n = tn;
	for(int i = 0; i < n; i++){
		s2.insert(v[i]);
		ct2[v[i]]++;
	} 
	for(int i = 0; i < n - 1; i++){
		ct2[v[i]]--;
		if(!ct2[v[i]]){
			auto a = s2.find(v[i]);
			s2.erase(a);
		}
		s1.insert(v[i]);
		if(s1.size() == i+ 1 && s2.size() == n - i - 1 && s1.size() == *(--s1.end()) && *(--s2.end()) == s2.size())ans.pb(mp(i + 1, n - i -1));
	}
	cout << ans.size() << ln;
	for(auto a : ans){
		cout << a.st << " " << a.nd << ln;
	}
} 
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);  
  cin >> t;
  while(t--){
  	solve();
  }
}