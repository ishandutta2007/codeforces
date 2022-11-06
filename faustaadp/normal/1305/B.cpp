#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
string s;
ll hz;
vector<ll> v;
vector<vector<ll> > z;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    ll n = s.length();
    ll r = n - 1;
    for(ll i = 0; i < n; i++)
    {
    	if(s[i] == '(')
    	{
    		while(i < r)
    		{
    			if(s[r] == ')')
    			{
    				v.pb(i + 1);
    				v.pb(r + 1);
    				r--;
    				break;
    			}
    			r--;
    		}
    	}
    }
    if(v.empty())
    	cout << 0 << "\n";
    else
    {
    	sort(v.begin(), v.end());
    	cout << 1 << "\n";
    	cout << v.size() << "\n";
    	for(ll i = 0; i < v.size(); i++)
    		cout << v[i] << " ";
    	cout << "\n";
    }
}