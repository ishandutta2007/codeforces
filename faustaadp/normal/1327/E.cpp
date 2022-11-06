#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n, x[202020], mo = 998244353;
void hai(ll aa)
{
    if(aa >= (ll)pow(10LL, n))
        return ;
    ll lst = -1, byk = 0, tmp = aa;
    for(ll i = 1; i <= n; i++)
    {
        if(lst == (tmp % 10))
            byk++;
        else
        {
            if(byk > 0)
                x[byk]++;
            byk = 1;
        }
        lst = tmp % 10;
        tmp /= 10;
    }
    x[byk]++;
    hai(aa + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n;
    // hai(0);
    x[1] = 10;
    x[2] = 180;
    ll z = 810;
    for(ll i = 3; i <= n; i++)
    {
        x[i] = (x[i - 1] * 10LL) % mo;
        x[i] = (x[i] + z) % mo;
        z = (z * 10LL) % mo;
    }
    for(ll i = n; i >= 1; i--)
        cout << x[i] << " ";
    cout << "\n";
}