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
const int N = 1000;
int n, vis[N];
vector <bool> ip(N<<2); 
vi pr;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  fill(ip.begin(), ip.end(), 1);
  for(int i = 2; i <= (N<<2); i++){
  	if(ip[i]){
  		for(int j = i*i; j <= (N<<2); j+=i)ip[j] = 0;
  		pr.pb(i);
  	}
  } 	
  for(int i = 3; i < N;i++){
  	int num = i, ct = 0;
  	while(!ip[num]){num++;ct++;}
  	assert(ct <= i/2);
  }  
  cin >> n;
  vector <pii> ans; 
  for(int i = 1; i < n; i++){
  	if(i == 1)ans.pb(mp(i, n));
  	ans.pb(mp(i, i + 1));
  }
  int i = 1;

  while(!ip[n]){
  	n++;
  	while(vis[i])i++;
  	ans.pb(mp(i, i + 2));
  	vis[i + 2] = 1;
  	++i;
  }
  cout << ans.size() << ln;
  for(auto a : ans)cout << a.st << " " << a.nd << ln;

}