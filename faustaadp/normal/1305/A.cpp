#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll t, n, i, a[NN], b[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n;
    	for(ll i = 1; i <= n; i++)
    		cin >> a[i];
    	for(ll i = 1; i <= n; i++)
    		cin >> b[i];
    	sort(a + 1, a + 1 + n);
    	sort(b + 1, b + 1 + n);
    	for(ll i = 1; i <= n; i++)
    		cout << a[i] << " ";
    	cout << "\n";
    	for(ll i = 1; i <= n; i++)
    		cout << b[i] << " ";
    	cout << "\n";
    }
}