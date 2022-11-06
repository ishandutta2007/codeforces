#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n, woi[101010], b[101010], t;
string bin(ll aa)
{
   string z = "";
    for(ll i = 62; i >= 0; i--)
        if(aa & (1LL << i))
            z += "1";
        else
            z += "0";
    return z;
}
ll kan(ll aa, ll pos)
{
    string fe = bin(aa);
    string ge = fe;
    ll udh = 0;
    for(ll i = 1; i <= 62; i += 2)
    {
        ge[i + 1] = fe[i];
        if(fe[i] == fe[i + 1])
            ge[i] = '0';
        else
            ge[i] = '1';
    } 
    ll H = 0;
    // cout << "\n" << fe << "\n" << ge << "\n";
    // if(pos > 1)
    // {
    //     if((pos % 4 == 2) || (pos % 4 == 3))
    //         ge[60] = '0';
    //     else
    //         ge[60] = '1';
    //     if((pos % 4 == 2) || (pos % 4 == 1))
    //         ge[59] = '0';
    //     else
    //         ge[59] = '1';
    // }
    for(ll i = 0; i <= 62; i++)
        if(ge[i] == '1')
            H += (1LL << (62LL - i));
    return H;
}
ll cek(ll aa)
{
    ll pos = (aa + 2) / 3;
    ll za = 1, pr = 0, he, lpr = 0;
    for(ll i = 1; i <= 999; i++)
    {
        lpr = pr;
        pr += za;
        if(pr >= pos)
        {
            he = za + (pos - lpr - 1); 
            break;
        }
        za *= 4LL;
    }
    if(aa % 3 == 1)
        return he;
    else
    if(aa % 3 == 2)
        return kan(he, pos);
    else
        return he^kan(he, pos);
    // cout << pos << " " << aa << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    // ll K = 500, te = 0;
    // for(ll f = 1; f <= 50; f++)
    // {
    //     ll udh = 0;
    //     for(ll i = 1; i <= K; i++)
    //     {
    //         if(udh)break;
    //         for(ll j = 1; j <= K; j++)
    //         {
    //             if(udh)break;
    //             for(ll k = 1; k <= K; k++)
    //             {
    //                 if(udh)break;
    //                 if(b[i] == 0 && b[j] == 0 && b[k] == 0 && ((i^j^k) == 0))
    //                 {
    //                     b[i] = 1;
    //                     b[j] = 1;
    //                     b[k] = 1;
    //                     udh = 1;
    //                     woi[++te] = i;
    //                     woi[++te] = j;
    //                     woi[++te] = k;
    //                     // cout << bin(i) << "  " << bin(j) << " " << bin(k) << "\n";
    //                 }
    //             }
    //         }
    //     }
    // }
    // return 0;
    // for(ll i = 1; i <= 50; i++)
        // cout << i << "  " << cek(i) << "  " << woi[i] << "\n";
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << cek(n) << "\n" ;
    }
}