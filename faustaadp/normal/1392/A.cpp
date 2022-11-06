#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        if(a[1] == a[n])
            cout << n << "\n";
        else
            cout << 1 << "\n";
    }
}