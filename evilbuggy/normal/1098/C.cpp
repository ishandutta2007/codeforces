#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll calc(ll x, ll n, int k){
	ll ans = 0;
	ll prod = 0;
	while(n > 0){
		ans += prod*min(1LL*n, x);
		n -= x;
		x *= k;
		prod++;
	}
	return ans;
}

ll d[100005];
deque<int> q[100005];
int p[100005], deg[100005];

void fill(int i, int m){
	while(m--){
		d[i] = 1;
		i++;
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

    int n;
    ll s;
    cin>>n>>s;
    if(s < 2*n - 1 || s > 1LL*n*(n+1)/2){
    	cout<<"No"<<endl;
    	return 0;
    }
    cout<<"Yes"<<endl;
    s -= n;
    int k = 1, m = n;
    while(s < calc(1, n, k))k++;
    memset(d, 0, sizeof(d));
    memset(deg, 0, sizeof(deg));
    d[0] = 1; m--;
    ll cur = 0;
    for(ll i = 1; i < n && m > 0; i++){
    	ll l = 1, r = min(1LL*m, d[i-1]*k);
    	// cout<<endl;
    	// for(int mid = l; mid <= r; mid++){
    	// 	ll maxi = 1LL*(m - mid)*(m - mid + 1)/2;
    	// 	ll mini = calc(mid, m, k);
    	// 	cout<<i<<" "<<mid<<" "<<mini<<" "<<maxi<<endl;
    	// }
    	// cout<<endl;
    	while(l <= r){
    		int mid = l + (r-l)/2;
    		ll maxi = 1LL*(m - mid)*(m - mid + 1)/2;
    		ll mini = calc(mid, m, k);
    		// cout<<i<<" "<<mini<<" "<<maxi<<" "<<mid<<" "<<s<<" "<<cur<<endl;
    		if(cur + i*m + mini <= s && s <= cur + i*m + maxi){
    			if(cur + i*m + maxi == s){
    				d[i] = mid;
    				fill(i + 1, m - mid);
    				m = 0;
    				break;
    			}
    			d[i] = mid;
    			m -= mid;
    			cur += i*d[i];
    			break;
    		}
    		if(s > cur + i*m + maxi){
    			r = mid - 1;
    		}else{
    			l = mid + 1;
    		}
    	}
    }
    int ptr = 1;
    for(int i = 0; i < n; i++){
    	if(d[i] == 0)break;
    	for(int j = 0; j < d[i]; j++){
    		q[i].push_back(ptr);
    		ptr++;
    	}
    }
    for(int i = 1; i < n; i++){
    	if(d[i] == 0)break;
    	for(auto x : q[i]){
    		int y = q[i-1].front();
    		deg[y]++;
    		p[x] = y;
    		if(deg[y] == k)q[i-1].pop_front();
    	}
    }
    for(int i = 2; i <= n; i++){
    	cout<<p[i]<<" ";
    }
}