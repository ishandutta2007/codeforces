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
int n, a, b, on, ans;
vi edge[100005];
bool ct[2];
void DFS(int nd, int par, int sum){
	int co = 0;
	if(edge[nd].size() == 1)ct[sum&1]=1;
	for(int i : edge[nd]){
		if(edge[i].size() == 1)co++;
		if(i != par)DFS(i, nd, sum + 1);
	}
	ans += max(0, co - 1);
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> n;
  on = n - 1;
  int lf;
  while(--n){
  	cin >> a >> b;
  	edge[a].pb(b);
  	edge[b].pb(a);
  }
  for(int i = 1; i <= on + 1; i++)if(edge[i].size() == 1)lf = i;
  DFS(lf, -1, 0);
  cout << (ct[0]&&ct[1]? 3 : 1) << " " << on - ans;

}