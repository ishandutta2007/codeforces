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
int t;
void solve(){
	string mat[9];
	bool vis[9][9];
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < 9; i++){
		cin >> mat[i];
	}
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(!vis[i][j]){
				if(mat[i][j] == '1')mat[i][j] = '2';
				else mat[i][j] = '1';
				for(int q = 0; q < 9; q++){vis[i][q] = 1;vis[q][j] = 1;}
				int l = i - i%3, r = j - j % 3; 
				for(int ii = 0; ii < 3; ii++){
					for(int jj = 0; jj < 3; jj++){
						vis[ii + l][jj + r] = 1;
					}
				}
			}
		}
	}
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++)cout << mat[i][j];
		cout << ln;
	}
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> t;
  while(t--)solve();
}