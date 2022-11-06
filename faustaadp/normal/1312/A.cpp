#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	ll n, m;
    	cin >> n >> m;
    	if(n % m == 0)
    		cout << "YES\n";
    	else
    		cout << "NO\n";
    }
}