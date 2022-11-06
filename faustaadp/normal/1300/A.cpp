#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 2e5 + 5;
ll t, n;    
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll sum = 0;
        ll ban = 0;
        ll has = 0;
        for(ll i = 1; i <= n; i++)
        {
            ll ta;
            cin >> ta;
            if(ta == 0)
            {
                ta++;
                has++;
            }
            sum += ta;
        }
        if(sum == 0)
            has++;
        cout << has << "\n";
    }
}