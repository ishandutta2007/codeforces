#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll inf = (1LL<<60);

int n, m;
pair<ll, ll> a[1000005];
ll k, prime[15];
pair<ll, int> costvec[(1<<15)][15];
ll dp[(1<<15)][15];
vector<int> mvec[1000005];

void add(int mask, pair<ll, int> tmp){
	for(int i = 0; i < m; i++){
		if(tmp < costvec[mask][i])swap(tmp, costvec[mask][i]);
	}
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    ll mgcd = 0;
    for(int i = 1; i <= n; i++){
    	cin>>a[i].first;
    	mgcd = __gcd(mgcd, a[i].first);
    }
    if(mgcd == 1){
    	cout<<0<<endl;
    	return 0;
    }
    for(int i = 1; i <= n; i++){
    	cin>>a[i].second;
    }
    m = 0;
    for(ll i = 2; i * i <= mgcd; i++){
    	if(mgcd%i == 0){
    		while(mgcd%i == 0)mgcd /= i;
    		prime[m++] = i;
    	}
    }
    if(mgcd != 1)prime[m++] = mgcd;
    for(int i = 1; i <= n; i++){
    	ll x = 1;
    	for(int j = 0; j < m; j++){
    		while(a[i].first%prime[j] == 0){
    			a[i].first /= prime[j];
    			x *= prime[j];
    		}
    	}
    	a[i].first = x;
    }
    sort(a + 1, a + n + 1);

    for(int mask = 0; mask < (1<<m); mask++){
    	for(int i = 0; i < m; i++){
    		costvec[mask][i] = {inf, -1};
    	}
    }
    int cnt;
    ll prodval[(1<<m)], prval[m];
    for(int i = 1; i <= n; i++){
    	if(i == 1 || a[i].first != a[i-1].first){
    		cnt = 0;
    		ll x = a[i].first;
    		for(int j = 0; j < m; j++){
    			prval[j] = 1;
    			while(x%prime[j] == 0){
    				x /= prime[j];
    				prval[j] *= prime[j];
    			}
    		}
    		prodval[0] = 1;
    		for(int mask = 1; mask < (1<<m); mask++){
    			for(int j = 0; j < m; j++){
    				if(mask&(1<<j)){
    					prodval[mask] = prodval[mask^(1<<j)] * prval[j];
    					break;
    				}
    			}
    		}
    	}
    	if(cnt == m)continue;
    	cnt++;
    	for(int mask = 1; mask < (1<<m); mask++){
    		if(prodval[mask] <= k){
    			add(mask, {a[i].second, i});
    		}
    	}
    }

    for(int mask = 1; mask < (1<<m); mask++){
    	for(int j = 0; j < m; j++){
    		if(costvec[mask][j].first == inf)break;
    		mvec[costvec[mask][j].second].push_back(mask);
    	}
    }

    for(int mask = 0; mask < (1<<m); mask++){
    	for(int i = 0; i <= m; i++){
    		dp[mask][i] = inf;
    	}
    }
    dp[0][0] = 0;
    const int compmask = (1<<m) - 1;
    for(int i = 1; i <= n; i++){
    	if(mvec[i].empty())continue;
    	for(int sz = m; sz > 0; sz--){
    		for(auto mask : mvec[i]){
    			int nmask = compmask ^ mask;
    			for(int msk = nmask; ; msk = (msk - 1)&nmask){
    				dp[msk^mask][sz] = min(dp[msk^mask][sz], dp[msk][sz-1] + a[i].second);
    				if(!msk)break;
    			}
    		}
    	}
    }
    ll ans = inf;
    for(int i = 1; i <= m; i++){
    	if(dp[compmask][i] != inf){
    		ans = min(ans, dp[compmask][i] * i);
    	}
    }
    if(ans == inf)cout<<-1<<endl;
    else cout<<ans<<endl;
}