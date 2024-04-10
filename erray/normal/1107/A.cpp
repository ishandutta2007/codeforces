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
int T, n;
string s; 
void solve(){
	cin >> n >> s;
	if(n == 2){
		if(s[0] >= s[1]){
			cout << "NO";
		}
		else{
			cout << "YES" << ln << 2 << ln << s[0] << " " << s[1];
		}
	}
	else{
		cout << "YES" << ln << 2 << ln;
		for(int i = 0; i < n; i++){
			cout << s[i];
			if(i == 0)cout << " ";
		}
	}
	cout << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> T;
  while(T--)solve();
}