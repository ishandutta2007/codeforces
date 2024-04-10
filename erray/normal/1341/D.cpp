
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
#define max(aa, bb) (aa > bb ? aa : bb)
#define min(aa, bb) (aa < bb ? aa : bb)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
string arr[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"}; 
int n, k;
bool dp[2005][2005];
vector <pii>  prob[2005];
void prnt(int ind, int tk){
	for(int i = prob[ind].size() - 1; i >= 0; i--){
		if(tk - prob[ind][i].st >= 0 && dp[ind + 1][tk - prob[ind][i].st]){
			cout << prob[ind][i].nd;
			if(ind != n - 1)prnt(ind + 1, tk - prob[ind][i].st);
			return;
		}
	}
}
void solve(){
	cin >> n >> k;
	vector <string> v(n); 
	for(int i = 0; i < n; ++i)cin >> v[i];
	for(int i = 0; i < n; ++i){
		string ms = v[i];
		for(int j = 0; j < 10; ++j){
			string dn = arr[j];
			int cst = 0;
			for(int q = 0; q < 7; ++q){
				cst += (dn[q] == '1' && ms[q] == '0');
				if(dn[q] == '0'&& ms[q] == '1'){
					cst = -1;
					break;
				}
			}
			if(cst != -1)prob[i].pb(mp(cst, j));
		}
	}
	dp[n][0] = 1;
	for(int i = n - 1; i >= 0; --i){
		for(int j = 0; j <= k; ++j){
			if(!dp[i + 1][j])continue;
			for(auto a : prob[i])if(j + a.st <= k)dp[i][j + a.st] = 1;
		}
	}
	if(!dp[0][k])cout << -1 << ln;
	else prnt(0, k);
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}