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
ll k;
string s;
ll cnt[NN];
ll np[NN];
ll udah = 0;
string jaw;
void cetak(ll z)
{
    string zz = to_string(z);
    cout << zz.length() << "\n" << zz << "\n";
}
void hai(ll pos, string z)
{
    if(z.length() > 0 && np[stoll(z)])
    {
        ll ln = jaw.length();
        if(ln > z.length())
        {
            jaw = z;
        }
        return ;
    }
    if(pos == k)
        return ;
    hai(pos + 1, z + s[pos]);
    hai(pos + 1, z);
}
void cari()
{
    jaw = "99999";
    udah = 0;
    hai(0, "");
    cetak(stoll(jaw));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    np[1] = 1;
    for(ll i = 2; i <= 10000; i++)
        if(!np[i])
            for(ll j = i * i; j <= 10000; j += i)
                np[j] = 1;

    while(t--)
    {
        cin >> k;
        cin >> s;
        for(ll i = 0; i < 10; i++)
            cnt[i] = 0;
        for(ll i = 0; i < k; i++)
            cnt[s[i] - '0']++;
        // cout << cnt[1] << "__\n";
        if(cnt[1])cetak(1);
        else if(cnt[4])cetak(4);
        else if(cnt[6])cetak(6);
        else if(cnt[8])cetak(8);
        else if(cnt[9])cetak(9);
        else if(cnt[2] > 1)cetak(22);
        else if(cnt[3] > 1)cetak(33);
        else if(cnt[5] > 1)cetak(55);
        else if(cnt[7] > 1)cetak(77);
        else cari();
    }
}