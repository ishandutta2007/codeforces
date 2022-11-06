#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 2e5 + 5;
ll t, n, has, a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	has = 0;
    	vector<ll> isi;
    	cin >> n;
    	for(ll i = 1; i <= n; i++)
    		cin >> a[i];
    	for(ll i = 1; i <= n; i++)
    		for(ll j = i + 1; j <= n; j++)
    			isi.pb(a[j] - a[i]);
    	sort(isi.begin(), isi.end());
    	for(ll i = 0; i < isi.size(); i++)
    		if(i == 0 || isi[i] != isi[i - 1])
    			has++;
    	cout << has << "\n";
    }
}