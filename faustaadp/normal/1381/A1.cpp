#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n;
char a[NN];
char b[NN];
vector<ll> isi;
void hey(ll aa)
{
    for(ll i = 1; i <= aa; i++)
        if(a[i] == '1')
            a[i] = '0';
        else
            a[i] = '1';
    ll j = aa;
    for(ll i = 1; i <= aa; i++)
    {
        if(i >= j)
            break;
        swap(a[i], a[j]);
        j--;
    }
}
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
        ll te = 0;
        isi.clear();
        for(ll i = n; i >= 1; i--)
        {
            if(a[i] != b[i])
            {
                if(a[1] == b[i])
                {
                    isi.pb(1);
                    hey(1);
                }
                isi.pb(i);
                hey(i);
            }
            // cout << a[i] <<"_" << b[i] << "\n";
        }
        cout << isi.size() << " ";
        for(ll i = 0; i < isi.size(); i++)
            cout << isi[i] << " ";
        cout << "\n";
    }
}