#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e4 + 5;
ll t, n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            ll ta;
            cin >> ta;
            if(i % 2 == 1)
                cout << abs(ta);
            else
                cout << -abs(ta);
            cout << " ";
        }
        cout << "\n";
    }
}