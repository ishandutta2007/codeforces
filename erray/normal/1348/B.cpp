#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair  
#define st first 
#define nd second 
#define all(v)  v.begin(),v.end()
#define max(aa, bb) (aa > bb ? aa : bb)
#define min(aa, bb) (aa < bb ? aa : bb)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vi v(n);
		set <int> s; 
		for(int i = 0; i < n; ++i){
			cin >> v[i];
			s.insert(v[i]);
		}
		if(s.size() > k){
			cout << -1 << ln;
		}
		else {
			cout << k*n << ln;
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < k - s.size(); ++j)cout << 1 << " ";
				for(int a : s)cout << a << " ";
			}
			cout << ln;
		}
	}
}