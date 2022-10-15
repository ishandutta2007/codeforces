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
		int n;
		cin >> n;
		ll ans = 0, m = 2;
		for(int i = 0; i < n - 1; ++i){
			if(i < n / 2 - 1)ans += m;
			else ans -= m;
			m<<=1;
		}
		ans += m;
		cout << ans << ln;
	}
}