#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 1e5 + 5;
ll t, n, has, a[NN];
string s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	has = 0;
    	cin >> s;
    	n = s.length();
    	for(ll i = 0; i < n; i++)
    		a[i] = s[i] - 'a';
    	if(n >= 2 && a[0] == a[1])
    	{
    		a[1] = 100;
    		has++;
    	}
    	for(ll i = 2; i < n; i++)
    	{
    		if(a[i] == a[i - 1] || a[i] == a[i - 2])
    		{
    			has++;
    			a[i] = 100;
    		}
    	}
    	cout << has << "\n";
    	// cout << depe(0, 27, 28) << "\n";
    }
}