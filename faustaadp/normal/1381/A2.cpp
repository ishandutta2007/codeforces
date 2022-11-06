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
ll L, R, tuk, rev;
char car(ll pos)
{
    char H;
    if(!tuk)
        H = a[L + pos - 1];
    else
        H = a[R - pos + 1];
    if(rev)
    {
        if(H == '1')
            H = '0';
        else
            H = '1';
    }
    return H;
}
void ubah(ll pos)
{
    ll H = 0;
    if(!tuk)
        H = L + pos - 1;
    else
        H = R - pos + 1;
    a[H] = 1 - H;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> n;
        L = 1;
        R = n;
        tuk = 0;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i <= n; i++)
            cin >> b[i];
        rev = 0;
        isi.clear();
        for(ll i = n; i >= 1; i--)
        {
            if(car(i) != b[i])
            {
                if(car(1) == b[i])
                {
                    isi.pb(1);
                    ubah(1);
                }
                isi.pb(i);
                tuk = 1 - tuk;
                rev = 1 - rev;
            }
            if(!tuk)
                R--;
            else
                L++;
            // cout << L << "  " << R << "\n";
            // cout << a[i] <<"_" << b[i] << "\n";
        }
        cout << isi.size() << " ";
        for(ll i = 0; i < isi.size(); i++)
            cout << isi[i] << " ";
        cout << "\n";
    }
}