#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#include <bits/stdc++.h>
      
using namespace std;
  
const int MAXN = 1e5 + 7;

int a[MAXN];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    sort(a, a + n);

    int ans = 0;
    multiset <int> ms;
    for (int i = n - 1; i >= 0; --i) {
    	
    	if (ms.size() && *ms.rbegin() > a[i]) {
    		ms.erase(ms.find(*ms.rbegin()));
    		++ans;
    	}

    	ms.insert(a[i]);
    }

    cout << ans << '\n';
    return 0;
}