#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t, n;
string s;
ll b[5050][5050];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = s.length();
        for(ll i = (n - 1); i >= 0; i--)
            for(ll j = 0; j < n; j++)
            {
                if(i >= j)
                    b[i][j] = 1;
                else
                if((b[i + 1][j - 1] == 1) && (s[i] == s[j]))
                    b[i][j] = 1;
                else
                    b[i][j] = 0;
                // if(b[i][j])
                    // cout << i << " " << j << "_A\n";
            }
        ll ki = 0, ka = n - 1;
        string kiri = "";
        string kanan = "";
        string tengah = "";
        while((ki < ka) && (s[ki] == s[ka]))
        {
            kiri += s[ki];
            kanan += s[ka];
            ki++;
            ka--;
        }
        reverse(kanan.begin(), kanan.end());
        ll h1 = 0, h2 = 0;
        for(ll i = ki; i < ka; i++)
            if(b[ki][i])
                h1 = i - ki + 1;
        for(ll i = ka; i > ki; i--)
            if(b[i][ka])
                h2 = ka - i + 1;
        if(ki == ka)
            h1 = 1;
        // cout << h1 << " " << h2 << "\n";
        if(h1 > h2)
        {
            for(ll i = ki; i < (ki + h1); i++)
                tengah += s[i];
        }
        else
        {
            for(ll i = ka; i > (ka - h2); i--)
                tengah += s[i];
        }
        cout << kiri + tengah + kanan << "\n";
    }
}