#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

ll n, k;

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
   	cin >> n >> k;
   	vector<ll> t;
   	while(n){
   		t.pb(n % k);
   		n /= k;
   	}
   	vector<ll> ans;
   	for (int i = 0; i < t.size(); i++){
   		if (t[i] >= k){
   			if (i + 1 == t.size()){
   				t.pb(0);
   			}
   			t[i + 1] += t[i] / k;
   			t[i] %= k;
   		}
   		if (i % 2 == 0){
			ans.pb(t[i]);
		} else {
			if (t[i] == 0){
				ans.pb(0);
				continue;
			}
			ans.pb(k - t[i]);
			if (i + 1 == t.size()) t.pb(0);
			t[i + 1]++;
		}
   	}

   	cout << ans.size() << "\n";
   	for (int x : ans) cout << x << ' ';
}