#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e6 + 5;
const ll mo = 1e9 + 7;
ll n;
ll udah;
string s;
void jawab(ll L1, ll R1, ll L2, ll R2)
{
    if(udah)return ;
    if(L1 > R1)return ;
    if(L2 > R2)return ;
    if((R1 - L1 + 1) < (ll)(n / 2))return ;
    if((R2 - L2 + 1) < (ll)(n / 2))return ;
    udah = 1;
    L1++;
    L2++;
    R1++;
    R2++;
    cout << L1 << " " << R1 << " " << L2 << " " << R2 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s;
        udah = 0;
        for(ll i = 0; i < n; i++)
            if(s[i] == '0')
            {
                jawab(i, n - 1, i + 1, n - 1);
                jawab(0, i, 0, i - 1);
            }
        if(!udah)
            jawab(0, n - 2, 1, n - 1);
    }
}