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
#define mid (s + e)/2
#define ln '\n'
#define MAX (ll)(1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll; 
string s;
int ct[N*10];
ll ans;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> s;	
  int cnt2=0, cnt1 = 0;
  for(int i = 0; i < s.size(); i++){
  	int ct2 = 0;
  	while(i < s.size() && s[i] == 'v'){
  		ct2++;i++;
  	}
  	ct[i] = max(ct2-1, 0);
  	cnt2+=max(ct2-1, 0);
  }
  for(int i = 0; i < s.size(); i++){
  	cnt1+=ct[i];
  	cnt2-=ct[i];
  	if(s[i]=='o')ans+=((ll)cnt1*cnt2);
  }
  cout << ans;
}