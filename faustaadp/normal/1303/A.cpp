#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e6 + 5;
ll t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        ll kiri = -1;
        ll kanan = -1;
        for(ll i = 0; i < s.length(); i++)
            if(s[i] == '1')
            {
                if(kiri == -1)
                    kiri = i;
                kanan = i;
            }
        ll has = 0;
        if(kiri != -1 && kanan != -1)
        {
            for(ll i = kiri; i <= kanan; i++)
                has += (s[i] == '0');
        }
        cout << has << "\n";
    }
}