    #include <bits/stdc++.h>
    #define ll long long
    #define db long double
    #define x first
    #define y second
    #define mp make_pair
    #define pb push_back
    #define all(a) a.begin(), a.end()
     
    using namespace std;
     
    int n;
    int a[111];
     
    int main(){
    #ifdef LOCAL
    	freopen("A_input.txt", "r", stdin);
    	//freopen("A_output.txt", "w", stdout);
    #endif
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
     
    	cin >> n;
    	vector<int> t(n);
    	for (int i = 0; i < n; i++) cin >> t[i];
     
    	int ans = 0;
     
    	while(1){
    		if (t.size() == 0) break;
    		ans++;
    		sort(all(t));
    		vector<int> d;
    		for (int x : t) if (x % t[0] != 0) d.pb(x);
    		t = d;
    	}
     
     
    	cout << ans;
    }