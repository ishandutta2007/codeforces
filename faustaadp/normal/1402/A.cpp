#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll t, n, k;
char a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n >> k;
    	for(ll i = 1; i <= n; i++)
    		cin >> a[i];
    	ll gagal = 0;
    	for(ll i = 1; i <= k; i++)
    	{
    		ll nol = 0;
    		ll satu = 0;
    		for(ll j = i; j <= n; j += k)
    		{
    			if(a[j] == '0')nol = 1;
    			if(a[j] == '1')satu = 1;
    		}
    		if(nol == 1 && satu == 1)
    		{
    			gagal = 1;
    			break;
    		}
    		if(nol)
    		{
    			for(ll j = i; j <= n; j += k)
    				a[j] = '0';
    		}
    		else
    		if(satu)
    		{
    			for(ll j = i; j <= n; j += k)
    				a[j] = '1';
    		}
    	}
    	if(!gagal)
    	{
    		ll nol = 0;
    		ll sat = 0;
    		for(ll i = 1; i <= k; i++)
    		{
    			if(a[i] == '1')sat++;
    			if(a[i] == '0')nol++;
    		}
    		if(nol * 2 > k)gagal = 1;
    		if(sat * 2 > k)gagal = 1;
    		if(gagal)cout << "NO\n";
    		else cout << "YES\n";
    	}
    	else cout << "NO\n";
    }
}