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
		ll nw = 1;
		vi ans;
		while(n){
			if(nw > n){
				ans.pb(n);
				break;
			}
			ans.pb(nw);
			n-=nw;
			nw<<=1;
		}
		sort(all(ans));
		cout << ans.size() - 1 << ln;
		for(int i = 0; i < (int)ans.size() - 1; ++i)cout << ans[i + 1] -  ans[i] << " ";
		cout << ln;
	}
}