#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 3e5 + 10;
const ll F = 2e9;

ll n, x[MAXN], b[MAXN];
char c[MAXN];
ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> x[i] >> c[i];
	for (ll i = 0; i < n; i++){
		b[i] = n;
		for (ll j = i+1; j < n; j++)
			if (c[i] == c[j]){
				b[i] = j;
				break;
			}
	}
	ll last = -1;
	for (ll i = 0; i < n;){
		ll j = i;
		while (j < n && c[j] != 'G') j++;
		ll nxt = j;
	
		ll mn[2] = {(ll)2e9, (ll)2e9}, mx[2] = {-(ll)2e9, -(ll)2e9};
		for (ll k = last+1; k < nxt; k++)
			if (c[k] == 'R')
				mn[0] = min(mn[0], x[k]), mx[0] = max(mx[0], x[k]);
			else
				mn[1] = min(mn[1], x[k]), mx[1] = max(mx[1], x[k]);
		for (ll k = 0; k < 2; k++)
			mx[k] = max(mx[k], mn[k]);
		if (last == -1 && nxt == n)
			ans += mx[1] - mn[1], ans += mx[0] - mn[0];
		else if (last == -1){
			for (ll k = 0; k < 2; k++)
				if (mn[k] != F)
					ans += x[nxt] - mn[k];
		}
		else if (nxt == n){
			for (ll k = 0; k < 2; k++)
				if (mx[k] != F)
					ans += mx[k] - x[last];
		}
		else{
			ll temp = (x[nxt] - x[last]);
			ll temp2[2] = {0, 0};
			for (ll k = last+1; k < nxt; k++)
				if (b[k] < nxt){
					if (c[k] == 'R')
						temp2[0] = max(temp2[0], x[b[k]] - x[k]);
					else
						temp2[1] = max(temp2[1], x[b[k]] - x[k]);
				}
			if (mn[0] == F)
				temp2[0] = temp;
			else
				temp2[0] = max({temp2[0], mn[0] - x[last], x[nxt] - mx[0]});
			if (mn[1] == F)
				temp2[1] = temp;
			else
				temp2[1] = max({temp2[1], mn[1] - x[last], x[nxt] - mx[1]});
			ans += min(temp*2, temp*3 - temp2[0] - temp2[1]);
		}

		last = nxt;
		i = j+1;
	}
	cout << ans << endl;
	return 0;
}