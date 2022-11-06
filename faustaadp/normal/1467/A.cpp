#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e5 + 5;
ll t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	ll n;
    	cin >> n;
    	ll te = 9;
    	for(ll i = 1; i <= n; i++)
    	{
    		if(i == 1)
    			cout << 9;
    		else
    		if(i == 2)
    			cout << 8;
    		else
    		{
    			cout << te;
    			te++;
    			te %= 10;
    		}
    	}
    	cout << "\n";
    }
}