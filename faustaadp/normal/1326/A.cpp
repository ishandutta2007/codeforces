#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t, n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
            cout << -1 << "\n";
        else
        {
            cout << 2;
            for(ll i = 1; i < n; i++)
                cout << 3;
            cout << "\n";
        }
    }
}