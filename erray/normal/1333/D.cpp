#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h> 
#define pb emplace_back
#define mp make_pair 
#define st first 
#define nd second 
#define all(v) v.begin(),v.end()
#define umap unordered_map
#define L nd<<1
#define R (L)|1
#define mid ((s + e)>>1)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, k, ct;
string s;
vector <pair <int, bool> > av;
vi v;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> n >> k >> s;
  for(int i = 0; i < n - 1; i++)if(s[i] == 'R' && s[i]!=s[i + 1])v.pb(i);
  while(!v.empty()){
  	ct++;
  	for(int i = 0; i < v.size(); i++)av.pb(mp(v[i], i == v.size()-1));
  	for(int a : v)swap(s[a] , s[a + 1]);
  	v.clear();
  	for(int i = 0; i < n - 1; i++)if(s[i] == 'R' && s[i]!=s[i + 1])v.pb(i);
  }
	if(k < ct || k > av.size()){
		cout << -1;
		return 0;
	}
	int f = av.size() - k;
	int ind = 0;
	while(k--){
		vi ans;
		ans.pb(av[ind].st);
		int kl = av[ind++].nd;
		while(f && !kl){
			kl += av[ind].nd;
			ans.pb(av[ind++].st);
			--f;
		}
		cout << ans.size() << " ";
		for(int i : ans)cout << i  + 1 << ' ';
		cout << ln;
	}
}