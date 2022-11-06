#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 4e5 + 5;
ll t, n, has, a[NN], te, x[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	has = 0;
    	te++;
    	cin >> n;
    	for(ll i = 1; i <= n; i++)
    		cin >> a[i];
    	sort(a + 1, a + 1 + n);
    	for(ll i = 1; i <= n; i++)
    	{
    		if(x[a[i]] == te)
    			a[i]++;
    		if(x[a[i]] != te)
    			has++;
    		x[a[i]] = te;
    	}
    	cout << has << "\n";
    }
}