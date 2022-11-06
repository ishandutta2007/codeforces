#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll t, a[NN], n;
ll cak(ll pos)
{
	if(pos <= 1 || pos >= n)return 0;
	if(a[pos - 1] < a[pos] && a[pos] > a[pos + 1])return 1;
	if(a[pos - 1] > a[pos] && a[pos] < a[pos + 1])return 1;
	// cout << a[pos - 1] << " x " << a[pos] << " x " << a[pos + 1] << "\n";
	return 0;
}
ll cek(ll pos)
{
	return cak(pos - 1) + cak(pos) + cak(pos + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n;
    	for(ll i = 1; i <= n; i++)
    		cin >> a[i];
    	ll hz = 0;
    	for(ll i = 2; i < n; i++)
    	{
    		if(a[i - 1] < a[i] && a[i] > a[i + 1])hz++;
    		if(a[i - 1] > a[i] && a[i] < a[i + 1])hz++;
    	}
    	ll ada = 0;
    	ll has = hz;
    	for(ll i = 1; i <= n; i++)
    	{
    		hz -= cek(i);
    		ll tmp = a[i];
    		a[i] = tmp + 1;has = min(has, hz + cek(i));	

    		a[i] = tmp - 1;has = min(has, hz + cek(i));	

    		a[i] = 0;has = min(has, hz + cek(i));	
    		a[i] = 1e10;has = min(has, hz + cek(i));	

    		if(i > 1)
    		{
    			a[i] = a[i - 1];has = min(has, hz + cek(i));	
    			a[i] = a[i - 1] + 1;has = min(has, hz + cek(i));	
    			a[i] = a[i - 1] - 1;has = min(has, hz + cek(i));	
    		}

    		if(i < n)
    		{
    			a[i] = a[i + 1];has = min(has, hz + cek(i));	
    			a[i] = a[i + 1] + 1;has = min(has, hz + cek(i));	
    			a[i] = a[i + 1] - 1;has = min(has, hz + cek(i));	
    		}

    		a[i] = tmp;
    		hz += cek(i);
    	}
    	cout << has << "\n";
    }
}